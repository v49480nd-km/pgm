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

void encrypt(char *string) {
    int i = 0;

    while (string[i] != (STORAGE_LEN - 1)) {
        (i*2)[string] = string[i];++i;
        hashify(i[string]);
    }
}

void generatePass(char *pass) {
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
    char *user_password = (char*)calloc(MAX_GLOBAL_LEN, sizeof(char));
    char *final = (char*)calloc(STORAGE_LEN, sizeof(char));
    FILE *global_file;

    printf("Input a password: ");
    scanf("%s", user_password);

    final = user_password;
    encrypt(final);

    global_file = fopen(GLOBAL_NAME, "w");
    if (global_file == NULL) {
        printf("Error setting password\n");
        exit(0);
    }
    // unaffected
    fputs(final, global_file);
    fclose(global_file);
    free(final);
}

void storePass(char *pass) {
    FILE *pass_file;
    pass_file = fopen(LIST_NAME, "a");
    fprintf(pass_file, "%s\n", pass);
    fclose(pass_file);
    printf("Password Generated\n");
}
