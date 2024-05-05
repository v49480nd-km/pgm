#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "utils.h"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Not valid, use pgm --help for commands\n");
        exit(0);
    }

    if (strcmp(argv[1], SET) == 0)
    {
        setPassphrase();
    }
    else if (strcmp(argv[1], GEN) == 0)
    {
        Pair pair;

        if (access("passphrase.txt", F_OK) != 0)
        {
            printf("Please set Passphrase.\n");
            exit(0);
        }

        initPair(&pair);
        getId(&pair);
        generate(&pair);
        storePair(&pair);
    }
    else if (strcmp(argv[1], LIST) == 0)
    {
        listPairs();
    }
    else if (strcmp(argv[1], DELETE) == 0)
    {
        printf("Deleting pair\n");
    }
    else if (strcmp(argv[1], DELETE_ALL) == 0)
    {
        printf("Clearing stored pairs\n");
        deletePairs();
    }
    else
    {
        helpScreen();
    }

    return 0;
}
