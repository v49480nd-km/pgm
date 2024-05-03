#include <stdio.h>

#include "utils.h"

int main(int argc, char* argv[]) {
    Pair test;

    printf("Hello world\n");
    initPair(&test);
    generate(&test);
    printf("%s\n", test.pwd);
}
