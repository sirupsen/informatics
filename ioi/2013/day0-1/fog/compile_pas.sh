#!/bin/bash

NAME=fog

/usr/bin/gcc -O2 -g -c graderlib.c -o graderlib.o
/usr/bin/fpc -dEVAL -XS -O2 -o$NAME grader.pas
