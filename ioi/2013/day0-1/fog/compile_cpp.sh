#!/bin/bash

NAME=fog

/usr/bin/g++ -DEVAL -static -O2 -o $NAME grader.c graderlib.c paddle.o $NAME.cpp
