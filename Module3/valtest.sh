#!/bin/bash

# applies valgrind to all tests on list.c
printf "\n Results from Put test \n\n"
valgrind --leak-check=full testP | grep ==

printf "\nResults from Get test\n\n"
valgrind --leak-check=full testG | grep ==

printf "\nResults from Apply test\n\n"
valgrind --leak-check=full testA | grep ==

printf "\nResults from Remove test\n\n"
valgrind --leak-check=full testR | grep ==
