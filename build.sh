#!/bin/bash

echo "Compiling..."
clang -std=c17 -Ofast -Werror -Wextra -Wall -Wfloat-equal \
    -Wundef -Wshadow -Wformat=2 -Wpedantic main.c utils.c -c

if [[ -f main.o && -f utils.o ]] then
    echo "Linking..."
    gcc -std=gnu18 -Ofast -Werror -Wextra -Wall -Wfloat-equal \
    -Wundef -Wshadow -Wformat=2 -Wpedantic main.o utils.o -o pgm
else
    echo "Error"
fi
