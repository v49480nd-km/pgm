#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "utils.h"

/* GENERATE SECTION */
int _checkPassphrase(void) {
    FILE* fp;
    char* passphrase = (char*)malloc(PHRASE_LEN * sizeof(char));
    char* user_guess = (char*)malloc(PHRASE_LEN * sizeof(char));
    printf("Input passphrase: ");
    scanf("%s", user_guess);
    fp = fopen("passphrase.txt", "r"); /* rename */

    if (fp == NULL) {
        printf("Could not verify passphrase, please try again.\n");
        exit(0);
    }

    fgets(passphrase, PHRASE_LEN, fp);
    if (strcmp(user_guess, passphrase) == 0) {
        return 1;
    }

    fclose(fp);
    free(user_guess);
    free(passphrase);
    return 0;
}

void genPwd(Pair *pair) {
    int rand_int;
    srand(time(NULL));
    for (int i = 0; i < PWD_LEN; i++) {
        rand_int = rand() % NUM_CHARS;
        pair->pwd[i] = PWD_CHARS[rand_int];
    }
}

void getDesc(char *desc) {
    printf("Input a description less than 4 characters. EX: youtube\n");
    for (int i = 0; i < DESC_LEN; i++) {
        desc[i] = getchar();
    }
    fflush(stdin); /* being safe */
}

void initPair(Pair *newPair) {
    newPair->desc = (char*)malloc(DESC_LEN * sizeof(char));
    newPair->pwd = (char*)malloc(PWD_LEN * sizeof(char));
    newPair->next = NULL;
}

void setPassphrase(void) {
    FILE* fp;
    char* user_string = (char*)malloc(PHRASE_LEN * sizeof(char));

    if (access("passphrase.txt", F_OK) == 0) { /* rename once pgm complete */
        printf("Passphrase already set.\n");
        exit(0);
    }

    printf("Input passphrase LESS THAN 30 characters.\n");
    scanf("%s", user_string);
    fp = fopen("passphrase.txt", "w"); // rename that file when pgm is done
                                       //
    if (fp == NULL) {
        printf("Could not generate password. Please try again.\n");
        exit(0);
    }

    fprintf(fp, "%s", user_string);
    printf("Passphrase stored, DO NOT FORGET!!!\n");
    fclose(fp);
    free(user_string);
}


/* LIST SECT */
void listPairs(void) {
    FILE* fp;
    char* pair = (char*)malloc(STORAGE_LEN * sizeof(char));
    int key = _checkPassphrase();

    if (key == 1) {
        fp = fopen("hidden.txt", "r"); // rename once done
        printf("Listing...\n");

        while (fgets(pair, STORAGE_LEN, fp)) {
            printf("%s", pair);
        }
        fclose(fp);
        free(pair);
        exit(0);
    }
    printf("Incorrect passphrase.\n");
    free(pair);
}

/* DELETE SECT */
int searchId(void) {
    FILE* fp;
    char* cur_id = (char*)malloc(DESC_LEN * sizeof(char));
    char* desired = (char*)malloc(DESC_LEN * sizeof(char));
    char cur_char;
    int char_count = 0, del_line = 0, line_count = 1;
    getDesc(desired);
    fp = fopen("hidden.txt", "rt"); /* rename once done */

    if (fp == NULL) {
        printf("Could not delete pair.\n");
        exit(0);
    }

    while ((cur_char = fgetc(fp)) != EOF) {
        char_count++;

        if (char_count <= DESC_LEN) {
            cur_id[char_count - 1] = cur_char;
        }

        if (cur_char == '\n') {
            char_count = 0;
            line_count++;
        }

        if (strcmp(cur_id, desired) == 0) {
            del_line = line_count;
            break;
        }
    }
    free(cur_id);
    free(desired);
    fclose(fp);
    return del_line;
}

void deletePair(int del_line) {
    FILE *read, *write;
    char cur = 'f';
    int lc = 1;
    read = fopen("hidden.txt", "r");
    write = fopen("temp.txt", "w");

    if ((read == NULL) || (write == NULL)) {
        printf("Can't delete pair.\n");
        exit(0);
    }
    while (cur != EOF) {
        cur = fgetc(read);

        if (cur == '\n') {
            lc++;
        }

        if (lc != del_line) {
            fputc(cur, write);
        }
    }
    fclose(read);
    fclose(write);
    _switchFiles();
}

void deletePairs(void) {
    if ((remove("hidden.txt") != 0)) { /* rename file once pgm complete */
        printf("Unable to delete, please try again.\n");
        exit(0);
    }
    printf("Pairs deleted.\n");
}

void _switchFiles(void) {
    if (remove("hidden.txt") != 0) {
        remove("temp.txt");
        printf("Error deleting pair.\n");
        exit(0);
    }
    rename("temp.txt", "hidden.txt");
}

// HELP
void helpScreen(void) {
    printf(
        "-h -> show commands\n"
        "-g -> generate and store password\n"
        "-l -> list all pairs\n"
        "-d -> delete pair by id\n"
        "-D -> remove all pairs\n"
    );
}

/* STORAGE SECTION */
void hashify(const char *key) {
    int key = 0;
    size_t key_len = LENGTH(key);

    for (size_t i = 0; i < key_len; i++) {
        key += key[i] * key[i];
    }
    return key % MAX_LINES;
}

void storePair(Pair *pair)
{
    FILE* fp;
    fp = fopen("hidden.txt", "a"); /* rename file once pgm is "complete" */
    if (fp == NULL) {
        printf("Could not open file. Please try again.\n");
        exit(0);
    }
    fprintf(fp, "%s:%s\n", pair->desc, pair->pwd);
    fclose(fp);
    free(pair->desc);
    free(pair->pwd);
}
