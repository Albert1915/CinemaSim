#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include "backend.h"
#include "custServ.h"

static char* filmList[MAX_NODE] = {0};
static char* airingList[3] = {0};
static int schedules[MAX_NODE][MAX_NODE];

void initCinema(hash* studioA, hash* studioB, hash* studioC) {
    char* filename = "cinemaSch.data";
    int colored[MAX_NODE] = {0};
    for (int i=0; i<MAX_ARR; i++) {
        studioA[i] = NULL;
        studioB[i] = NULL;
        studioC[i] = NULL;
    }

    parseFilm(filename, schedules);
    parseTitle(filename, filmList);
    colorized(schedules, colored);

    for (int i=0; i<MAX_NODE; i++) {
        if (colored[i] == 0 || colored[i] == 1 || colored[i] == 2) {
            if (!airingList[colored[i]]) {
                airingList[colored[i]] = strdup(filmList[colored[i]]);
            }
        }
    }
}   

char* buyTicket(hash* studioA, hash* studioB, hash* studioC, char* name) {
    int opt;
    char* film;

    printf("Berikut adalah daftar Film yang tersedia: \n");
    opt = getFilm(opt)-1;
    if (isFilmAvailable(filmList[opt])) {
        film = filmList[opt];
        if (opt == 0) opt = addCust(studioA, name, film);
        if (opt == 1) opt = addCust(studioB, name, film);
        if (opt == 2) opt = addCust(studioC, name, film);
        if (!opt) {
            if (filmSuggestion(film)) return buyTicket(studioA, studioB, studioC, name);
            else return NULL;
        }
    } else {
        if (filmSuggestion(filmList[opt])) return buyTicket(studioA, studioB, studioC, name);
        else return NULL;
    }
    return film;
}

int addCust(hash* cinema, char* name, char* film) {
    hash custData = malloc(sizeof(struct hash_t));
    custData->name = calloc(255, sizeof(char));
    custData->film = calloc(255, sizeof(char));
    custData->next = NULL;

    int hashVal = generateHash(name);
    strcpy(custData->name, name);
    strcpy(custData->film, film);

    if (cinema[hashVal] != NULL) {
        return 0;
    } else {
        cinema[hashVal] = custData;
    }
}

void getCinemaStats(hash* obj) {
    for (int i=0; i<MAX_ARR; i++) {
        hash temp = obj[i];
        if (temp != NULL) {
            printf("[%d] %s -> %s\n", i, temp->name, temp->film);
        }
    }
}

int getFilm() {
    int opt;
    for (int i=0; i<MAX_NODE; i++) {
        printf("[%d] %s\n", i+1, filmList[i]);
    }
    printf("Masukkan pilihan anda: ");
    scanf("%d", &opt);
    return opt;
}

static char* generateAlias(char* name) {
    char* temp = calloc(255, sizeof(char));
    char* alias = calloc(100, sizeof(char));

    strcpy(temp, name);

    temp = strtok(temp, " ");
    strcat(alias, temp);
    do {
        temp = strtok(NULL, " ");
        if (temp) {
            char x = temp[0];
            strncat(alias, &x, 1);
        }
    } while (temp != NULL);
    free(temp);
    return alias;
}

static int generateHash(char* name) {
    int val = 0;
    unsigned long ctr = 0;
    for (int i=0; i<strlen(name)-1; i++) {
        ctr += i+1 < 10 ? (int) name[i]*10 + 1+1 : (int)name[i]*100 + i+1;
    }
    ctr = (unsigned long)pow(ctr, 2);
    while(length(ctr) > 2) {
        val += ctr%10;
        ctr = ctr/10;
    }
    return val;
}

static unsigned length(const unsigned long num) {
    if (num < 10) return 1;
    return 1 + length(num/10);
}

int filmSuggestion(char* film) {
    char ans[3];
    printf("%s belum ditayangkan saat ini, apakah anda ingin memesan film lainnya ?\n", film);
    printf("Jawaban [y/n]: ");
    scanf("%s", ans);
    if (ans[0] == 'y') {
        return 1;
    } else {
        return 0;
    }
}

static int isFilmAvailable(char* film) {
    if (airingList[0] == 0) return 0;
    for (int i=0; i<3; i++) {
        if (!strcmp(film, airingList[i])) return i+1;
    }
    return 0;
}

static void parseTitle(char* filename, char* obj[6]) {
    FILE* rawFile = fopen(filename, "r+");
    char* buff = calloc(255, sizeof(char));
    char* temp = calloc(255, sizeof(char));
    int ctr = -1;
    int isData = 0;

    while (fgets(buff, 255, rawFile)) {
        temp = strtok(buff, "\n");
        if (!strcmp(temp, "title_Start")) isData = 1;
        if (!strcmp(temp, "title_End")) isData = 0;

        if (isData && strcmp(buff, "title_Start") && strcmp(buff, "title_End")) {
            obj[++ctr] = strdup(temp);
        }
    }
}

static void parseFilm(char* filename, int obj[MAX_NODE][MAX_NODE]) {
    FILE* rawFile = fopen(filename, "r+");
    char* buff = calloc(255, sizeof(char));
    char* temp = calloc(255, sizeof(char));
    int isData = 0;
    int idx = -1;

    for (int i=0; i<MAX_NODE; i++) {
        for (int j=0; j<MAX_NODE; j++) {
            obj[i][j] = 0;
        }
    }

    while (fgets(buff, 255, rawFile)) {
        temp = strtok(buff, "\n");
        if (!strcmp(temp, "data_start")) isData = 1;
        if (!strcmp(temp, "data_end")) isData = 0;

        if (isData && strcmp(buff, "data_start") && strcmp(buff, "data_end")) {
            idx = atoi(strtok(temp, " "));
            do {
                temp = strtok(NULL, " ");
                obj[idx][atoi(temp)] = 1;
            } while (temp != NULL);
        }
    }
}

static void colorized(int matrices[MAX_NODE][MAX_NODE], int* res) {
    int color[MAX_NODE];
    color[0] = 0;

    int colorUsed[MAX_NODE];

    for (int i=1; i<MAX_NODE; i++) {
        color[i] = -1;
    }

    for (int i=0; i<MAX_NODE; i++) {
        colorUsed[i] = 0;
    }

    for (int u=1; u<MAX_NODE; u++) {
        for (int v=0; v<MAX_NODE; v++) {
            if (matrices[u][v]) {
                if (color[v] != -1) {
                    colorUsed[color[v]] = 1;
                }
            }
        }

        int col;
        for (col=0; col<MAX_NODE; col++) {
            if (!colorUsed[col]) break;
        }
        color[u] = col;
        
        for (int v=0; v<MAX_NODE; v++) {
            if (matrices[u][v]) {
                if (color[v] != -1) {
                    colorUsed[color[v]] = 0;
                }
            }
        }
    }

    for (int x=0; x<MAX_NODE; x++) res[x] = color[x];
}

static void orderCanceled() {
    printf("Mohon Maaf atas ketidaknyamanannya...\n");
}