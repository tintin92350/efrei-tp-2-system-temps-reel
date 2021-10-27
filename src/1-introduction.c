/**
 * @file 1-introduction.c
 * @author Quentin RODIC (quentin.rodic@efrei.net)
 * @brief Question 1 - Introduction
 * @version 0.1
 * @date 2021-10-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>

#include "1-introduction.h"

/**
 * @brief Entry point of the program that test a 5s work
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char** argv) {
    printf("Task begin...\n");
    do_work(5000);
    printf("Task ended\n");
    return 0;
}