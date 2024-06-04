#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdint.h>
#include <stdlib.h>
// COMMANDS
#define DELETE "-d"
#define DELETE_ALL "-D"
#define FIND   "-f"
#define GEN    "-g"
#define HELP   "-h"
// NAMES
#define CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()"
#define GLOBAL_NAME "global.txt" // WILL CHANGE AND WHAT NOT
#define LIST_NAME "passes.txt" // WILL CHANGE AND WHAT NOT
// SIZES
#define MAX_GLOBAL_LEN 0x10
#define PWD_LEN 0x10
#define STORAGE_LEN 0x20

uint8_t checkGlobalPass();
uint8_t findPass();
uint8_t verifyGlobalPass();
void deleteAll();
void deletePass();
void encrypt(char *string);
void generatePass(char *pass);
void hashify(char c);
void helpScreen();
void setGlobalPass();
void storePass(char *pass);

#endif
