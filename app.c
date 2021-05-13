#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libs\backend.h"

int main(int argc, char* argv[]) {
    hash studioA[100];
    hash studioB[100];
    hash studioC[100];
    initCinema(studioA, studioB, studioC);
    // getData();

    addCust(studioA, "Keyaruga Keyaru", "Attack on Titan");
    addCust(studioA, "Keyaruga Kai", "Kaifuku no Kaijutsu");
    addCust(studioA, "Lynne Fuyuna", "Marciless");
    getCinemaStats(studioA);
}