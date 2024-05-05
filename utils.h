#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

// CLI MACROS
#define HELP "--help"
#define SET "--set-passphrase"
#define GEN "--generate"
#define LIST "--list"
#define DELETE "--delete"
#define DELETE_ALL "--delete-all"

// GENERATING MACROS
#define ID_LEN 2
#define PWD_LEN 20
#define PHRASE_LEN 30
#define STORAGE_LEN 23
#define PWD_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()"
#define NUM_CHARS sizeof(PWD_CHARS) / sizeof(PWD_CHARS[0]) - 1

typedef struct
{
    char* id;
    char* pwd;
} Pair;

void setPassphrase();
int checkPassphrase();
void initPair(Pair* pair);
void generate(Pair* pair);
void getId(Pair* pair);
void storePair(Pair* pair);
void listPairs();
void encrypt(Pair* pair);
void decrypt(const char* passphrase);
void deletePair(const char* id);
void deletePairs();
void helpScreen();

#endif
