#!/bin/bash

SRC=(main.c utils.c)
OBJ=(main.o utils.o)

echo "Compiling..."
gcc -std=gnu18 -Ofast -w main.c utils.c -c

if [[ -f main.o && -f utils.o ]] then
    echo "Linking..."
    gcc -std=gnu18 -Ofast -w  main.o utils.o -o pgm
else
    echo "Error"
fi
