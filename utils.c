#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "utils.h"

void initPair(Pair* newPair) {
    newPair->id = (char*)malloc(ID_LENGTH * sizeof(char));
    newPair->pwd = (char*)malloc(PWD_LENGTH * sizeof(char));
}

void generate(Pair* pair) {
    int rand_int;

    srand(time(NULL));

    for (int i = 0; i < PWD_LENGTH; i++) {
        rand_int = rand() % NUM_CHARS + 1;
        pair->pwd[i] = PWD_CHARS[rand_int];
    }
}
