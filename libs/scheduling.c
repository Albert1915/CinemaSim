#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include "scheduling.h"

// Note
// Collision will be handled w/ LL and linear probing
// So same index is some sort of expected

// Searching
// Hashed . Linear Probing
// Linear Search (Cuz hashed by Linear Probe)

// Sorting (Bubble Sort)
// Sorts out the content of each index in the array of LL

void addMember(hash hashTable, char* name) {
    // char* alias = generateAlias(name);
    // int hashVal = generateHash(name);
    int hashVal = 10;
    char* alias = "Kyaa";
    printf("[%d] %s\n", hashVal, alias);
}

static unsigned lengthOfNum(const unsigned long num) {
    if (num < 10) return 1;
    return 1 + lengthOfNum(num/10);
}

static char* generateAlias(char* name) {
    char* temp = malloc(255*sizeof(char));
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
    // Mengubah array of char menjadi array of int
    name = generateAlias(name);
    int val = 0;
    unsigned long ctr = 0;
    for (int i=0; i<strlen(name)-1; i++) {
        ctr += i+1 < 10 ? (int) name[i]*10 + i+1 : (int) name[i]*100 + i+1;
    }
    ctr = (unsigned long)pow(ctr, 2);
    while (lengthOfNum(ctr) > 2) {
        val += ctr%10;
        ctr = ctr/10;
    }
    
    return val;
}