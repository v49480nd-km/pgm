#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdint.h>
#include <stdlib.h>
// COMMANDS
#define DELETE "-d"
#define FIND   "-f"
#define GEN    "-g"
#define HELP   "-h"
// NAMES
#define CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()"
#define GLOBAL_NAME "global.txt" // WILL CHANGE AND WHAT NOT
#define LIST_NAME "passes.txt" // WILL CHANGE AND WHAT NOT
// SIZES
#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))
#define MAX_GLOBAL_LENGTH 30
#define PWD_LEN 20

uint8_t checkGlobalPass();
uint8_t findPass();
uint8_t verifyGlobalPass();
void deleteAll();
void deletePass();
void generatePass(char *pass);
void helpScreen();
void setGlobalPass();
void storePass(char *pass);

#endif
