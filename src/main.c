#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

int main(int argc, char *argv[]) {
    uint8_t globalPassExists = checkGlobalPass();
    /* if (argc != 2) { */
    /*     printf( */
    /*         "Arguments do no match\n" */
    /*         "Please use pgm -h for more help\n" */
    /*     ); */
    /*     exit(0); */
    /* } */

    if (!globalPassExists) {
        setGlobalPass();
    }

    /* if (strcmp(argv[1], HELP) == 0) { */
    /*     helpScreen(); */
    /* } else if (strcmp(argv[1], GEN) == 0) { */
    /*     char *pass = (char*)calloc(PWD_LEN, sizeof(char)); */
    /*     generatePass(pass); */
    /*     //storePass(pass); */
    /*     free(pass); */
    /* } */
}
