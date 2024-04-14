#include <stdio.h>

#define ID_LENGTH 0x3
#define SHORT_PIN_LENGTH 0x4
#define LONG_PIN_LENGTH 0x6
#define PWD_LENGTH 0x14
#define ID_CHAR_SIZE 0x24
#define PIN_CHAR_SIZE 0xA
#define PWD_CHAR_SIZE 0x48
#define ID_CHARS "abcdefghijklmnopqrstuvwxyz1234567890"
#define PIN_CHARS "1234567890"
#define PWD_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVXYZ1234567890!@#$%^&*()"

void
printToFile(FILE* file, const int STRING_SIZE, const char* string);

char*
generate(const int OUTPUT_SIZE, const int CHARSET_SIZE, const char* CHARSET);

void
storePair(const int STRING_SIZE, const char* encrypted_string);

void
setPassphrase(const char* user_passphrase);

void
listPairs(const char* user_passphrase);

char*
encrypt(const char* clean_string);

char*
decrypt(const char* user_passphrase);
