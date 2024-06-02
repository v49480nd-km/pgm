#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdint.h>
#include <stdlib.h>

#define CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()"

// COMMANDS
#define DELETE "-d"
#define FIND   "-f"
#define GEN    "-g"
#define HELP   "-h"

// SIZES
#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))
#define MAX_GLOBAL_LENGTH 30

uint8_t checkGlobalPass();
uint8_t findPass();
uint8_t verifyGlobalPass();
void deletePass();
void generatePass();
void helpScreen();
void setGlobalPass();
void storePass();

#endif
