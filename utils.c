#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "utils.h"

#define PWD_LENGTH 20
#define PWD_CHARS \
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()" \

int
generatePin() {
    int pin;

    srand(time(NULL));
    
    pin = rand() % (999 - 100 + 1) + 100;

    return pin;
}

char*
generatePwd() {
    int rand_int;
    char* pwd = (char*)malloc(PWD_LENGTH * sizeof(char));

    if (pwd == NULL) {
        printf("Error, memory not allocated\n");
        exit(0);
    }

    srand(time(NULL));

    for (int i = 0; i < PWD_LENGTH; i++) {
        rand_int = rand() % 72 + 1;
        pwd[i] = PWD_CHARS[rand_int];
    }

    return pwd;
}

void
storePwd(char pwd[PWD_LENGTH]) {
    FILE* storeFile;
    int pin;

    pin = generatePin();
    storeFile = fopen("config.txt", "a");

    fprintf(storeFile, "[%d] ", pin);

    for (int i = 0; i < PWD_LENGTH; i++) {
        fprintf(storeFile, "%c", pwd[i]);
    }

    fprintf(storeFile, "\n");
    fclose(storeFile);
}
