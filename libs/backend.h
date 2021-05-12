#ifndef __CX_SCH__
    #define __CX_SCH__
    #define MAX_ARR 100

    struct hash_t {
        char* name;
        char* film;
        struct hash_t* next;
    };
    typedef struct hash_t* hash;

    extern void initCinema(hash* obj);
    extern void addCust(hash* cinema, char* name, char* film);
    static char* generateAlias(char* name);
    static int generateHash(char* name);
    static int getHash(char* name);
    static hash isExist(char* ame);
    static hash getAddress(hash obj, char* name);
    static unsigned length(const unsigned long num);
#endif