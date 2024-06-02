#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "utils.h"

uint8_t checkGlobalPass() {
    FILE *global_file;
    global_file = fopen("password.txt", "r");

    if (global_file == NULL) {
        return 0;
    }
    fclose(global_file);
    return 1;
}

void generatePass(char *pass) {
    int rand_int;
    srand(time(NULL));

    for (int i = 0; i < PWD_LEN; i++) {
        rand_int = rand() % 72;
        pass[i] = CHARS[rand_int];
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
    char *temp;
    char *user_password = (char*)malloc(MAX_GLOBAL_LENGTH * sizeof(char));
    int char_count = 0;
    FILE *global_file;

    printf("Input a password: ");
    scanf("%s", user_password);

    while (user_password[char_count]) {
        char_count++;
    }

    temp = user_password;
    user_password = realloc(user_password, char_count * sizeof(char));
    if (user_password == NULL) {
        user_password = temp;
    }

    global_file = fopen("password.txt", "w");
    if (global_file == NULL) {
        printf("Error setting password\n");
        exit(0);
    }
    fputs(user_password, global_file);
    fclose(global_file);
    free(user_password);
}

void storePass(char *pass) {
    FILE *pass_file;
    pass_file = fopen("passes.txt", "a");
    fprintf(pass_file, "%s\n", pass);
    fclose(pass_file);
}
