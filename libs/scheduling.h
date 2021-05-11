#ifndef __CX_SCH__
    #define __CX_SCH__
    #define MAX_ARR 100
    struct hashtableElement_t {
        struct hashtableElement_t* next;
        char* node;
        char* data;
    };
    typedef struct hashtableElement_t* hash;
    extern void addMember(hash hashTable, char* name);
    static unsigned lengthOfNum(const unsigned long num);
    static int isHashed();
    static int isEmpty(struct hashtableElement_t obj);
    static char* generateAlias(char* name);
    extern int generateHash(char* name);
    
#endif