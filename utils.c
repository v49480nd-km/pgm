#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "utils.h"

void setPassphrase(void)
{
    FILE* fp;
    char* user_string = (char*)malloc(PHRASE_LEN * sizeof(char));

    if (access("passphrase.txt", F_OK) == 0)
    {
        printf("Passphrase already set.\n");
        exit(0);
    }

    printf("Input passphrase LESS THAN 30 characters.\n");
    scanf("%s", user_string);

    fp = fopen("passphrase.txt", "w");

    if (fp == NULL)
    {
        printf("Could not generate password. Please try again.\n");
        exit(0);
    }

    fprintf(fp, "%s", user_string);
    printf("Passphrase stored, DO NOT FORGET!!!\n");
    fclose(fp);
    free(user_string);
}

int checkPassphrase(void)
{
    FILE* fp;
    char* user_guess = (char*)malloc(PHRASE_LEN * sizeof(char));
    char* passphrase = (char*)malloc(PHRASE_LEN * sizeof(char));

    printf("Input passphrase: ");
    scanf("%s", user_guess);

    fp = fopen("passphrase.txt", "r");

    if (fp == NULL)
    {
        printf("Could not verify passphrase, please try again.\n");
        exit(0);
    }

    fgets(passphrase, PHRASE_LEN, fp);

    if (strcmp(user_guess, passphrase) == 0)
    {
        return 1;
    }

    fclose(fp);
    free(user_guess);
    free(passphrase);

    return 0;
}

void initPair(Pair* newPair)
{
    newPair->id = (char*)malloc(ID_LEN * sizeof(char));
    newPair->pwd = (char*)malloc(PWD_LEN * sizeof(char));
}

void generate(Pair* pair)
{
    int rand_int;

    srand(time(NULL));

    for (int i = 0; i < PWD_LEN; i++)
    {
        rand_int = rand() % NUM_CHARS;
        pair->pwd[i] = PWD_CHARS[rand_int];
    }
}

void getId(Pair* pair)
{
    char c;
    int i = 0;

    printf("Input a 2 letter id name Ex: ytbe\n");

    while (i < ID_LEN)
    {
        c = getchar();
        pair->id[i] = c;
        i++;
    }
}

void storePair(Pair* pair)
{
    FILE* fp;

    fp = fopen("hidden.txt", "a");

    if (fp == NULL)
    {
        printf("Could not open file. Please try again.\n");
        exit(0);
    }

    fprintf(fp, "%s:%s\n", pair->id, pair->pwd);
    fclose(fp);
    free(pair->id);
    free(pair->pwd);
}

void listPairs(void)
{
    FILE* fp;
    char* pair = (char*)malloc(STORAGE_LEN * sizeof(char));
    int key = checkPassphrase();

    if (key == 1)
    {
        fp = fopen("hidden.txt", "r");

        printf("Listing...\n");

        while (fgets(pair, STORAGE_LEN, fp))
        {
            printf("%s", pair);
        }

        fclose(fp);
        free(pair);
        exit(0);
    }

    printf("Incorrect passphrase.\n");
    free(pair);
}

/*
 * ABLE TO FIND PAIR BUT IS OUTPUTTING LINES HIGHER THAN LINE COUNT
 * IN FILE SO FIGURE THAT OUT I GUESS
 */
int searchId(FILE* file, const char* id)
{
    char* current_id = (char*)malloc(ID_LEN * sizeof(char));
    char* current_line = (char*)malloc(STORAGE_LEN * sizeof(char));
    int line_count = 0;

    while (fgets(current_line, STORAGE_LEN, file) != NULL)
    {
        line_count++;

        for (int i = 0; i < ID_LEN; i++)
        {
            current_id[i] = current_line[i];
        }

        if (strcmp(id, current_id) == 0)
        {
            free(current_id);
            free(current_line);

            return line_count;
            break;
        }
    }

    free(current_id);
    free(current_line);

    return 0;
}

void deletePair(void)
{
    FILE* fp;
    char* id = (char*)malloc(ID_LEN * sizeof(char));
    int pwd_line;

    printf("Input id to delete: ");
    scanf("%s", id);

    fp = fopen("hidden.txt", "r");

    pwd_line = searchId(fp, id);

    printf("Line num: %d", pwd_line);

    fclose(fp);
    free(id);
}

void deletePairs(void)
{
    if ((remove("hidden.txt") != 0))
    {
        printf("Unable to delete, please try again.\n");
        exit(0);
    }

    printf("Pairs deleted.\n");
}

void helpScreen(void)
{
    printf
    (
        "-h -> show commands\n"
        "-g -> generate and store password\n"
        "-l -> list all pairs\n"
        "-d -> delete pair by id\n"
        "-D -> remove all pairs\n"
    );
}
