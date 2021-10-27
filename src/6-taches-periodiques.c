/**
 * @file 6-taches-periodiques.c
 * @author Quentin RODIC (quentin.rodic@efrei.net)
 * @brief Question 6 - Tâches Périodiques
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
#include <pthread.h>

#include "1-introduction.h"

#include "utils.h"

/**
 * @brief Sleep method of periodic call
 * Infinite loop in order to repeate the action with a period.
 * do a work of 500 milliseconds
 * then wait 1 second
 * then repeat action
 * 
 */
void do_work_sleep() {
    while (processRunning) {
        do_work(500);   // 500 ms work
        printf("End of work of sleep process\n");
        sleep(1);       // Period of 1s
    }
}

/**
 * @brief Alarm method of periodic call
 * do a work of 500 milliseconds
 * then wait 1 second
 * then send an alarm in 1 second 
 * (that will repeat the process every second)
 * 
 * @param sig 
 */
void do_work_alarm(int sig) {
    do_work(500);   // 500 ms work
    printf("\tEnd of work of alarm process\n");
    alarm(1);       // Send alarm un 1 second
}

/**
 * @brief Show two ways of processing periodic functions.
 * 1 - We use sleep in order to wait for the instant we need to
 * process the next function. But we need a loop to repear process so
 * it takes some more times in order to process the loop and sleep function.
 * (not optimized)
 * 
 * 2 - We use the alarm method. This one seems better, because we only proceed
 * one time and then we schedule for 1 second later (alarm function).
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char const *argv[])
{
    // Register alarm signal
    signal(SIGALRM, do_work_alarm);
    signal(SIGINT, handleExit);

    do_work_alarm(SIGALRM);
    do_work_sleep();

    return 0;
}
