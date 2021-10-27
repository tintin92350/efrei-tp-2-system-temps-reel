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

timer_t gTimerid;

/**
 * @brief Start the timer for an interval of 1 second
 * before running the next one.
 */
void start_timer(void)
{
    struct itimerspec value;

    value.it_value.tv_sec = 1;
    value.it_value.tv_nsec = 0;

    value.it_interval.tv_sec = 1;
    value.it_interval.tv_nsec = 0;

    timer_create(CLOCK_REALTIME, NULL, &gTimerid);

    timer_settime(gTimerid, 0, &value, NULL);
}

/**
 * @brief Stop the timer (set the current timer to null 
 * in order to deactivate it)
 */
void stop_timer(void)
{
    struct itimerspec value;

    value.it_value.tv_sec = 0;
    value.it_value.tv_nsec = 0;

    value.it_interval.tv_sec = 0;
    value.it_interval.tv_nsec = 0;

    timer_settime(gTimerid, 0, &value, NULL);
}

/**
 * @brief Function called when timer trigger callback
 * 
 * @param sig 
 */
void timer_callback(int sig)
{
    printf("I'm working...\n");
    do_work(5);
}

/**
 * @brief 
 * 
 * Setting up a timer of 1 second then call an infinite loop
 * to let the timer's callback work.
 * 
 * observation: If the process (timer_callback) last for more than the period
 * the timer still work but will wait the end of the process to begin another one.
 * 
 * @param ac 
 * @param av 
 * @return int 
 */
int main(int ac, char **av)
{
    signal(SIGALRM, timer_callback);
    signal(SIGINT, handleExit);

    start_timer();
    
    while (processRunning);

    stop_timer();
}