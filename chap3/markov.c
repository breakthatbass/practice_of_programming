#include <stdio.h>
#include <stdlib.h>

enum {
    NPREF   = 2,    // number of prefix words
    NHASH   = 4093, // size of state hash table array
    MAXGEN  = 10000 // maximum words generated
};

typedef struct State State;
typedef struct Suffix Suffix;
struct State {      // prefix + suffix list
    char *pref[NPREF];      // prefix words
    Suffix *suf;            // suffix list
    State *next;            // next in hash table
};

struct Suffix {
    char *word;     // suffix
    Suffix *next;   // next in list of suffixes
};

State *statetab[NHASH];     // hash table of states