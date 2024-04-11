#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

int
main(/* int argc, char* argv[] */) {
    char* newPwd = generatePwd();

    storePwd(newPwd);
    free(newPwd);
    return 0;
}
