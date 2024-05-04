#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "utils.h"

void reallocString(const char* string)
{
    char* temp = string;
    int i = 0;

    while (string[i] != NULL)
    {
        i++;
    }

    string = (char*)realloc(string, i);

    if (string == NULL)
    {
        printf("Error setting passphrase, try again later.\n");
        string = temp;
    }

    printf("newsize: %d\n", (sizeof(string) / sizeof(string[0])));
}

void setPassphrase()
{
    FILE* fp;
    char* user_string = (char*)malloc(30 * sizeof(char));

    if (access("passphrase.txt", F_OK) == 0)
    {
        printf("Passphrase already set.\n");
        exit(0);
    }

    printf("Input passphrase LESS THAN 30 characters.\n");
    scanf("%s", user_string);
    printf("oldsize: %d\n", (sizeof(user_string) / sizeof(user_string[0])));
    reallocString(user_string);

    fp = fopen("passphrase.txt", "w");

    if (fp == NULL)
    {
        printf("Could not generate password. Please try again.\n");
        exit(0);
    }

    fprintf(fp, "%s\n", user_string);
    fclose(fp);
    free(user_string);
}

void initPair(Pair* newPair)
{
    newPair->id = (char*)malloc(ID_LENGTH * sizeof(char));
    newPair->pwd = (char*)malloc(PWD_LENGTH * sizeof(char));
}

void generate(Pair* pair)
{
    int rand_int;

    srand(time(NULL));

    for (int i = 0; i < PWD_LENGTH; i++)
    {
        rand_int = rand() % NUM_CHARS + 1;
        pair->pwd[i] = PWD_CHARS[rand_int];
    }
}

void getId(Pair* pair)
{
    char c;
    int i = 0;

    printf("Input a 4 letter id name Ex: ytbe\n");

    while (i < 4)
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

    fprintf(fp, "%s. %s\n", pair->id, pair->pwd);
    fclose(fp);
    free(pair->id);
    free(pair->pwd);
}

void deletePairs()
{
    if ((remove("hidden.txt") != 0) || (remove("passphrase.txt") != 0))
    {
        printf("Unable to delete, please try again.\n");
        exit(0);
    }

    printf("Pairs deleted.\n");
}

void helpScreen()
{
    printf
    (
        "--help       show commands\n"
        "--generate   generate and store password\n"
        "--list       list all pairs\n"
        "--delete     delete pair by id\n"
        "--delete-all remove all pairs\n"
    );
}
