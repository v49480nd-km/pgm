#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdlib.h>

// CLI MACROS
#define DELETE "-d"
#define DELETE_ALL "-D"
#define GEN "-g"
#define HELP "-h"
#define LIST "-l"
#define SET "-s"
// SIZING MACROS
#define DESC_LEN 4
#define NUM_CHARS (int)(sizeof(PWD_CHARS) / sizeof(PWD_CHARS[0]) - 1)
#define PHRASE_LEN 30
#define PWD_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()"
#define PWD_LEN 20
#define STORAGE_LEN 25

typedef struct
{
    char* desc; // e.g. youtube
    char* pwd;
} Pair;

// GENERATE SECTION
int _checkPassphrase(void); // return true or false
void genPwd(Pair* pair);
void getDesc(char* desc); // formerly id sorry for confusion
void initPair(Pair* pair);
void setPassphrase(void);
void storePair(Pair* pair);
// LIST SECTION
void listPairs(void);
// DELETE SECTION
void _switchFiles(void);
void deletePair(int del_line);
void deletePairs(void);
int searchId(void);
// HELP
void helpScreen(void);

#endif
