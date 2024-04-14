#!/bin/bash

CC=gcc
FLAGS=(-Wall -Wpedantic -V -0fast -pipe -std=gnu18)

$CC ${FLAGS} -c *.c
$CC ${FLAGS} -o pwd *.o
