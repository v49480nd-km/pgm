#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

// CLI MACROS
#define HELP "-h"
#define SET "-s"
#define GEN "-g"
#define LIST "-l"
#define DELETE "-d"
#define DELETE_ALL "-D"

// GENERATING MACROS
#define ID_LEN 2
#define PWD_LEN 20
#define PHRASE_LEN 30
#define STORAGE_LEN 23
#define PWD_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()"
#define NUM_CHARS (int)(sizeof(PWD_CHARS) / sizeof(PWD_CHARS[0]) - 1)

typedef struct
{
    char* id;
    char* pwd;
} Pair;

void setPassphrase(void);
int checkPassphrase(void);
void initPair(Pair* pair);
void generate(Pair* pair);
void getId(Pair* pair);
void storePair(Pair* pair);
void listPairs(void);
void encrypt(Pair* pair);
void decrypt(const char* passphrase);
int searchId(FILE* file, const char* id);
void deletePair(void);
void deletePairs(void);
void helpScreen(void);

#endif
