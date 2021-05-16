#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "libs\backend.h"
#include "libs\custServ.h"

// void preload() {
//     FILE* cache = fopen("queue.data", "r+");
// }
// void processPreload(queue cust, hash* stdA, hash* stdB, hash* stdC) {
// }

int main(int argc, char* argv[]) {
    hash studioA[100];
    hash studioB[100];
    hash studioC[100];
    queue cinemaQueue = NULL;
    initCinema(studioA, studioB, studioC);
    // preload(cinemaQueue, studioA, studioB, studioC);

    char* name = calloc(255, sizeof(char));
    char* film = calloc(255, sizeof(char));
    int opt = 0;
    int qSize = getQueueSize(cinemaQueue);

    printf("Selamat datang di Luminous Cinema!\n\n");
    while (opt!=4) {
        printf("[1] Lihat Antrian\n");
        printf("[2] Mengatri\n");
        printf("[3] Memesan\n");
        printf("[4] Keluar\n");
        printf("Input: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Jumlah Antrean %d!\n", getQueueSize(cinemaQueue));
                printf("Penonton pada Studio A: \n");
                getCinemaStats(studioA);
                printf("Penonton pada Studio B: \n");
                getCinemaStats(studioB);
                printf("Penonton pada Studio C: \n");
                getCinemaStats(studioC);
                printf("\n");
                break;
            case 2:
                printf("Masukkan Nama Anda: ");
                fflush(stdin);
                gets(name);
                enter_q(&cinemaQueue, name);
                break;
            case 3:
                char* custName = getCust(&cinemaQueue);
                if (custName == NULL) {
                    printf("Anda belum mengantri!\n");
                    break;
                }
                printf("Nama Customer: %s\n", custName);
                film = buyTicket(studioA, studioB, studioC, custName);
                if (film == NULL) break;
                getPayment(custName, film);
                break;
            case 4:
                printf("Terima kasih atas kunjungannya!\n");
                exit(0);
                break;
            default:
                printf("Masukkan pilihan yang sesuai!\n");
        }
        getch();
        system("cls");
    }
}