#ifndef __CX_SCH__
    #define __CX_SCH__
    #define MAX_ARR 100
    #define MAX_NODE 6
    struct hash_t {
        char* name;
        char* film;
        struct hash_t* next;
    };
    typedef struct hash_t* hash;

    extern void initCinema(hash* obj);
    extern void addCust(hash* cinema, char* name, char* film);
    extern void getCinemaStats(hash* obj);
    extern char** getAiring();
    extern void getData(int matrices[MAX_NODE][MAX_NODE], char* model[MAX_NODE]);
    static char* getSuggestions(); // Placeholders
    static char* generateAlias(char* name);
    static int generateHash(char* name);
    static unsigned length(const unsigned long num);
    static void colorized(int matrices[MAX_NODE][MAX_NODE], int* res);
    static void parseTitle(char* filename, char* obj[6]);
    static void parseFilm(char* filename, int obj[MAX_NODE][MAX_NODE]);

#endif