#!/bin/bash

CC=gcc
FLAGS=(-Wall -Wpedantic -V -0fast -pipe -std=gnu18)

echo "Compiling..."
sleep 3
$CC ${FLAGS} -c *.c

echo "Linking..."
sleep 3
$CC ${FLAGS} -o pgm *.o

echo "Finished"
