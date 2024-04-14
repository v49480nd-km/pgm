#include <stdlib.h>

#include "utils.h"

int
main(void) {
    char* random_test = generate(LONG_PIN_LENGTH, PIN_CHARS);

    storePair(LONG_PIN_LENGTH, random_test);
    free(random_test);

    return 0;
}
