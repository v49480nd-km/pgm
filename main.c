#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Not valid, use pgm --help for commands\n");
        exit(0);
    }

    if (strcmp(argv[1], GEN) == 0) {
        Pair pair;

        initPair(&pair);
        getId(&pair);
        generate(&pair);
        storePair(&pair);
    } else if (strcmp(argv[1], LIST) == 0) {
        printf("Listing pairs\n");
    } else if (strcmp(argv[1], DELETE) == 0) {
        printf("Deleting pair\n");
    } else if (strcmp(argv[1], DELETE_ALL) == 0) {
        printf("Clearing stored pairs\n");
    } else {
        helpScreen();
    }
}
