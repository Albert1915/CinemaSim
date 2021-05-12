#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libs\backend.h"

int main(int argc, char* argv[]) {
    hash studioA[100];
    initCinema(studioA);
    hash studioB[100] = {0};
    hash studioC[100] = {0};
    addCust(studioA, "Keyaruga Keyaru", "Kaifuku no Kaijutsu");
    addCust(studioA, "Keyaruga Kai", "Kaifuku no Kaijutsu");

}