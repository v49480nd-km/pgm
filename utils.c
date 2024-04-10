#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "utils.h"

void
generatePwd() {
    const int PWD_LENGTH = 20;
    const char PWD_CHARS[72] =
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()";
    
    int rand_int;

    srand(time(NULL));

    for (int i = 0; i < PWD_LENGTH; i++) {
        rand_int = rand() % 72 + 1;
        printf("%c", PWD_CHARS[rand_int]);
    }
}
