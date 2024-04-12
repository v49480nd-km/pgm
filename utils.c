#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "utils.h"

char*
generate(const int SIZE, const char* CHARSET) {
    int rand_int, charset_size;

    charset_size = strlen(CHARSET);
    char* new_item = (char*)malloc(SIZE * sizeof(char));

    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {
        rand_int = rand() % charset_size + 1;
        new_item[i] = CHARSET[rand_int];
    }

    for (int j = 0; j < SIZE; j++) {
        printf("%c", new_item[j]);
    }

    printf("\n");

    return new_item;
}
