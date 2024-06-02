#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

int main(int argc, char *argv[]) {
    int globalPassExists = checkGlobalPass();
    if (argc != 2) {
        printf(
            "Arguments do no match\n"
            "Please use pgm -h for more help\n"
        );
        exit(0);
    }

    if (!globalPassExists) {
        setGlobalPass();
    }
    
    if (strcmp(argv[1], HELP) == 0) {
        helpScreen();
    }
}
