#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "utils.h"

void
printToFile(FILE* file, const int STRING_SIZE, const char* string) {
    for (int i = 0; i < STRING_SIZE; i++) {
        fprintf(file, "%c", string[i]);
    }
}

char*
generate(const int SIZE, const char* CHARSET) {
    int rand_int;
    char* new_item = (char*)malloc(SIZE * sizeof(char));

    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {
        rand_int = rand() % (SIZE + 1);
        new_item[i] = CHARSET[rand_int];
    }

    return new_item;
}

void
storePair(const int STRING_SIZE, const char* encrypted_string) {
    FILE* store_file;
    char* pair_id = generate(ID_LENGTH, ID_CHARS);

    store_file = fopen("test.txt", "a");
    
    printToFile(store_file, ID_LENGTH, pair_id);
    fprintf(store_file, ". ");

    printToFile(store_file, STRING_SIZE, encrypted_string);
    fprintf(store_file, "\n");

    free(pair_id);
    fclose(store_file);
}
