#!/bin/bash

NAME=fog

/usr/bin/gcc -DEVAL -static -O2 -o $NAME grader.c graderlib.c paddle.o $NAME.c -lm
