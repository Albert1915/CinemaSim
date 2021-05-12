#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

#include "backend.h"

void initCinema(hash* obj) {
    for (int i=0; i<MAX_ARR; i++) {
        obj[i] = NULL;
    }
}

void addCust(hash* cinema, char* name, char* film) {
    int hashVal = generateHash(name);
    printf("%d %s %s\n", cinema, name, film);
    printf("[%d] Alias => %s\n",generateHash(name), generateAlias(name));
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

int generateHash(char* name) {
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

unsigned length(const unsigned long num) {
    if (num < 10) return 1;
    return 1 + length(num/10);
}