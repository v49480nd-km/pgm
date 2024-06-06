#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#include "utils.h"

uint8_t checkGlobalPass() {
    FILE *global_file;
    global_file = fopen(GLOBAL_NAME, "r");
    if (global_file == NULL) {
        return 0;
    }

    fclose(global_file);
    return 1;
}

void deleteAll() {
    if ((remove(LIST_NAME) == 0)) {
        printf("Passwords deleted\n");
        exit(0);
    }
    printf("Passwords could not be deleted\n");
    exit(0);
}

void encrypt(char str[], size_t size) {
    for (size_t i = 0; i < (size/2) - 1; i++) {
        hashify(str[i]);
    }
}

void generatePass(char pass[]) {
    uint8_t rand_int;

    for (uint8_t i = 0; i < PWD_LEN; i++) {
        rand_int = pass[i];
        printf("%u", rand_int);
    }
}

void hashify(char c) {
    if ((c%(MAX_GLOBAL_LEN/0x2))==0x0) {
        c-=(MAX_GLOBAL_LEN-((PWD_LEN/0x2)+0x1));
    } else if ((c%(PWD_LEN/0x4)==0)) {
        c+=(MAX_GLOBAL_LEN+((PWD_LEN/0x2)-0x1));
    } else if ((c%2)==0) {
        c+=c+PWD_LEN;
    } else {
        c=c+c;
    }
}

void helpScreen() {
    printf(
        "pgm -d => delete password\n"
        "pgm -f => find password\n"
        "pgm -g => generate password\n"
        "pgm -h => i think you know lol\n"
    );
}

void setGlobalPass() {
    char user_password[MAX_GLOBAL_LEN];
    char final[STORAGE_LEN];
    FILE *global_file;

    printf("Input a password: ");
    scanf("%s", user_password);

    for (size_t i = 0x0; i < ARR_LEN(user_password); i++) {
        final[i] = user_password[i];
        final[i+0x8] = user_password[i];
        if (!final[i]) {
            final[i] = 'x';
            final[i+0x8] = 'x';
        }
    }

    global_file = fopen(GLOBAL_NAME, "w");
    if (global_file == NULL) {
        printf("Error setting password\n");
        exit(0);
    }
    fputs(final, global_file);
    fclose(global_file);
}

void storePass(char pass[]) {
    FILE *pass_file;
    pass_file = fopen(LIST_NAME, "a");
    fprintf(pass_file, "%s\n", pass);
    fclose(pass_file);
    printf("Password Generated\n");
}
