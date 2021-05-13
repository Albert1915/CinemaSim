#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libs\backend.h"

int main(int argc, char* argv[]) {
    hash studioA[100];
    initCinema(studioA);
    hash studioB[100] = {0};
    hash studioC[100] = {0};
    char* titles[6] = {0};
    
    int graph[MAX_NODE][MAX_NODE] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };
    
    getData(graph, titles);

    addCust(studioA, "Keyaruga Keyaru", "Kaifuku no Kaijutsu");
    addCust(studioA, "Keyaruga Kai", "Kaifuku no Kaijutsu");
    addCust(studioA, "Lynne Fuyuna", "Marciless");
    getCinemaStats(studioA);
}