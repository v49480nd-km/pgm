#include <stdlib.h>

#include "utils.h"

int
main(void) {
    char* random_test = generate(PWD_LENGTH, PWD_CHARS);

    storePair(random_test);
    free(random_test);

    return 0;
}
