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
#define DESC_LEN 4
#define PWD_LEN 20
#define PHRASE_LEN 30
#define STORAGE_LEN 25
#define PWD_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()"
#define NUM_CHARS (int)(sizeof(PWD_CHARS) / sizeof(PWD_CHARS[0]) - 1)

typedef struct
{
    char* pwd;
    char* desc; // e.g. youtube
} Pair;

typedef struct
{
    int total_line;
    int l2d;  // line to delete
} DeletePair;

void setPassphrase(void);
int checkPassphrase(void); // return true or false
void initPair(Pair* pair);
void genPwd(Pair* pair);
void getDesc(char* desc); // formerly id sorry for confusion
void storePair(Pair* pair);
void listPairs(void);
void encrypt(Pair* pair);
void decrypt(const char* passphrase);
void searchId(DeletePair* nums);
void getFileLines(DeletePair* nums);
void deletePair(DeletePair* nums);
void deletePairs(void);
void helpScreen(void);

#endif
