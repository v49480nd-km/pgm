#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

int
main() {
    char* newPwd = generatePwd();

    storePwd(newPwd);
    free(newPwd);
    return 0;
}
