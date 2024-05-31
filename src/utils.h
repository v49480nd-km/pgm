#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdlib.h>

/* CLI MACROS */
#define DELETE "-d"
#define DELETE_ALL "-D"
#define GEN "-g"
#define HELP "-h"
#define LIST "-l"
#define SET "-s"
/* SIZING MACROS */
#define DESC_LEN 4
#define NUM_CHARS (int)(sizeof(PWD_CHARS) / sizeof(PWD_CHARS[0]) - 1)
#define PHRASE_LEN 30
#define PWD_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()"
#define PWD_LEN 20
#define STORAGE_LEN 25
#define MAX_LINES 100
#define LENGTH(a) sizeof(a) / sizeof(a[0])

typedef struct Pair {
    char *desc; /* e.g. youtube */
    char *pwd;
    struct Pair *next;
} Pair;

/* GENERATE SECTION */
int _checkPassphrase(void);
void genPwd(Pair *pair);
void getDesc(char *desc); /* formerly id sorry for confusion */
void initPair(Pair *pair);
void setPassphrase(void);
/* LIST SECTION */
void listPairs(void);
/* DELETE SECTION */
int searchId(void);
void deletePair(int del_line);
void deletePairs(void);
void _switchFiles(void);
/* HELP SECTION */
void helpScreen(void);
/* STORAGE SECTION */
void hashify(const char *key);
void storePair(Pair *pair);

#endif
