#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "utils.h"

char*
generatePwd() {
    const int PWD_LENGTH = 20;
    const char PWD_CHARS[72] =
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()";
    
    int rand_int;
    char* pwd = (char*)malloc(20 * sizeof(char));

    if (pwd == NULL) {
        printf("Error, memory not allocated\n");
        exit(0);
    }

    srand(time(NULL));

    for (int i = 0; i < PWD_LENGTH; i++) {
        rand_int = rand() % 72 + 1;
        pwd[i] = PWD_CHARS[rand_int];
    }

    for (int j = 0; j < PWD_LENGTH; j++) {
        printf("%c", pwd[j]);
    }

    return pwd;
}

void
storePwd(char pwd[20]) {
    FILE* storeFile;
    storeFile = fopen("config.txt", "a");

    fprintf(storeFile, "%d", *pwd);
    fclose(storeFile);
}
