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

int ttime = 0;

/**
 * @brief Execute task t2
 * 
 * @param executionTime time of execution of the task
 */
void t2(int executionTime) {
    do_work(executionTime);
    ttime+= executionTime;
}

/**
 * @brief Execute task t2
 * 
 * @param executionTime time of execution of the task
 */
void t3(int executionTime) {
    do_work(executionTime);
    ttime+= executionTime;
}

/**
 * @brief Execute task t2
 * 
 * @param executionTime time of execution of the task
 */
void t4(int executionTime) {
    do_work(executionTime);
    ttime+= executionTime;
}

/**
 * @brief Execute all tasks
 * 
 */
void task() {
    t2(333);
    t3(1000);
    t4(2000);
    t2(333);
    t3(1000);
    t2(333);
    t4(2000);
    t2(333);
    t3(1000);
    t2(333);
    t4(2000);
    t3(1000);
    t2(333);
}

/**
 * @brief 
 * 
 * We have to deal with a 333ms for t2 so in order to make it easier
 * we can take 333ms => 1s and t3 1s => 3s and finally t4 3s => 12s
 * 
 * Then juste divide by 3 all.
 * 
 * @param ac 
 * @param av 
 * @return int 
 */
int main(int ac, char **av)
{
    signal(SIGINT, handleExit);

    task();

    printf("total time : %d\n", ttime);

    return 0;
}