/**
 * @file 7-taches-periodiques.c
 * @author Quentin RODIC (quentin.rodic@efrei.net)
 * @brief Question 7 - Tâches Périodiques
 * @version 0.1
 * @date 2021-10-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <pthread.h>

#include "1-introduction.h"

#include "utils.h"

void t2(int executionTime) {
    do_work(executionTime);
}

void t3(int executionTime) {
    do_work(executionTime);
}

void t4(int executionTime) {
    do_work(executionTime);
}

/**
 * @brief 
 * 
 * 
 * @param ac 
 * @param av 
 * @return int 
 */
int main(int ac, char **av)
{
    signal(SIGINT, handleExit);

    t2(333);        // 0 - 333ms            t2 executé 1 fois
    t3(1000);       // 333ms - 1.333s       t3 executé 1 fois
    t4(666);        // 1.333ms - 2000ms
    t2(333);        // 2000ms - 2.333ms     t2 executé 2 fois
    t4(666);        // 2.333ms - 3000ms     t3 executé 2 fois
    t3(333);       // 3000ms - 3.333s       t3 executé 1 fois
    t4(666);        // 3.333ms - 4000ms     t3 executé 2 fois
}