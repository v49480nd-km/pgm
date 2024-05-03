#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

#define ID_LENGTH 4
#define PWD_LENGTH 20
#define PWD_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()"
#define NUM_CHARS sizeof(PWD_CHARS) / sizeof(PWD_CHARS[0]) - 1

typedef struct {
    char* id;
    char* pwd;
} Pair;

void initPair(Pair* newPair);
void generate(Pair* pair);
void storePair(Pair* pair);
void encrypt(Pair* pair);
void dencrypt();
void deletePair(const char* id);
void deletePairs();

#endif
