#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libs\scheduling.h"

int main(int argc, char* argv[]) {
    // char* txt = "Lynne Nyxhes Fuyuna";
    // generateHash(txt);
    hash table = malloc(100*sizeof(hash));
    char name[3][15] = {"Lynne Fuyuna", "Lynne Fuyuki", "Misaki Fuyuki"};
    // char film[] = "KnH"
    puts(table[0].data);
    for (int i=0; i<3; i++) {
        printf("%s\n", name[i]);
        // addMember(hashTable, name[i]);
    }

    char* ext = "exit";
    char* txt = calloc(255, sizeof(char));
    do {
        gets(txt);
        printf("%s => %d\n", txt, generateHash(txt));
    } while (strcmp(txt, ext));

}