#include <stdlib.h>

#include "utils.h"

int
main(/* int argc, char* argv[] */) {
    char* random_test = generate(PWD_LENGTH, PWD_CHARS);

    free(random_test);

    return 0;
}
