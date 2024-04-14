#include <stdio.h>

#define ID_LENGTH 3
#define SHORT_PIN_LENGTH 4
#define LONG_PIN_LENGTH 6
#define PWD_LENGTH 20
#define ID_CHARS "abcdefghijklmnopqrstuvwxyz1234567890"
#define PIN_CHARS "1234567890"
#define PWD_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVXYZ1234567890!@#$%^&*()"

void
printToFile(FILE* file, const int STRING_SIZE, const char* string);

char*
generate(const int SIZE, const char* CHARSET);

void
storePair(const char* encrypted_string);

void
setPassphrase(const char* user_passphrase);

void
listPairs(const char* user_passphrase);

char*
encrypt(const char* clean_string);

char*
decrypt(const char* user_passphrase);
