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
    extern void getCinemaStats(hash* obj);
    static char* getSuggestions(); // Placeholders
    static char* generateAlias(char* name);
    static int generateHash(char* name);
    static unsigned length(const unsigned long num);
#endif