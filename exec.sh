#!/bin/bash

./kfe -v -o run $1 && clang++ -o run main.cpp run.o && ./run