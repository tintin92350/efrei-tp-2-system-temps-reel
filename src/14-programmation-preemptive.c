/**
 * @file 14-programmation-preemptive.c
 * @author Quentin RODIC (quentin.rodic@efrei.net)
 * @brief Question 14 - Tâches Périodiques - Programmation preemptive
 * @version 0.1
 * @date 2021-10-28
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
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>

#include "1-introduction.h"

#include "utils.h"

timer_t gTimerid;

int taskId = 0;

/**
 * @brief Start the timer for an interval of 1 second
 * before running the next one.
 */
void start_timer(int timerValue, int timerInterval)
{
    struct itimerspec value;

    value.it_value.tv_sec = timerValue;
    value.it_value.tv_nsec = 0;

    value.it_interval.tv_sec = timerInterval;
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

void timer_callback(int sign)
{
    printf("I'm working on task %d...\n", taskId);

    if (taskId == 1)
        do_work(333);
    else if (taskId == 2)
        do_work(1000);
    else if (taskId == 3)
        do_work(2000);
}

/**
 * @brief 
 * 
 * We need to separate our program in 3 other process (fork).
 * Then we can instantiate 3 timers for each process.
 * 
 * @param ac 
 * @param av 
 * @return int 
 */
int main(int ac, char **av)
{
    signal(SIGALRM, timer_callback);
    signal(SIGINT, handleExit);

    taskId = 0;
    int periode[3] = { 2, 3, 4 };
    int prio[3] = { -15, 0, 15 };

    for (int i = 0; i < 3; i++)
    {
        taskId = i + 1;

        int pid = fork();

        if (pid == 0)
        {
            setpriority(getpid(), PRIO_PROCESS, prio[i]);
            start_timer(1, periode[i]);
            
            while (processRunning);

            stop_timer();
        }
    }

    wait(NULL);
    wait(NULL);
    wait(NULL);

    return 0;
}