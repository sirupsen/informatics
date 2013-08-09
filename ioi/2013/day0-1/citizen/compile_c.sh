#!/bin/bash

NAME=citizen

/usr/bin/gcc -DEVAL -static -O2 -o $NAME grader.c $NAME.c -lm
