/**
 * @file 5-taches-sporadiques.c
 * @author Quentin RODIC (quentin.rodic@efrei.net)
 * @brief Question 5 - Tâches Sporadiques
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

// Number of signal to treat
int numberOfSignal = 0;

/**
 * @brief Function that will do the work of signalhandler
 * 
 * @return void* 
 */
void *signalhandler_work()
{

    while (processRunning)
    {
        while (numberOfSignal)
        {
            // Simulate a hard work of 1 seconds
            printf("\t Work begin\n");
            do_work(1000);
            printf("\t Work ended\n");

            numberOfSignal--;
        }
    }
}

/**
 * @brief Handling signals
 * 
 * @param signum Signal
 */
void signalhandler(int signum)
{
    printf("Handling signal : %d\n", signum);

    numberOfSignal++;
}

/**
 * @brief Main entry point of the program.
 * Register a signal handler and wait for 10 seconds
 * 
 * observation: During the 5 seconds the signalHandler function 
 * is called we can send several signals (SIGUSR1) but only 2 will
 * be taken in consideration because the process has only a memory of
 * 2 signals and will forget any other received signals during this time. 
 * 
 * Upgrade: 
 * Why is the process ignoring the others signals ?
 * Because we send too many signals and it will only process 1 signal a time
 * and store another one in waiting state.
 * 
 * Why is this happening ?
 * Because signalhandler function is taking too much time
 * 
 * How to avoid this behaviour ?
 * We need to reduce the time of signalhandler.
 * In order to do that, we can process the signalhandler work in another 
 * thread. 
 * 
 * observation: With that method, we can catch all signal we need. But
 * the process is not totally done because only one signal is remembered by
 * the process one a time. So when we send 10 signals a time, in this window
 * we only treat 1 signal.
 * 
 * How to avoid that ?
 * We do an infinite loop that will process for 'n' signals.
 * 'n' increase when a signal is received by signalhandler
 * and decreased when a signal is treatd.
 * 
 * observation: need to protect the numberOfSignal for concurrency
 * 
 * Exemple of output:
 * $ process pid      8488
 * $ Handling signal : 10
 * $ Handling signal : 10
 * $ Handling signal : 10
 * $          Work begin
 * $          Work ended
 * $          Work begin
 * $          Work ended
 * $          Work ended
 * $          Work begin
 * $          Work ended
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char **argv)
{

    // Register SIGUSR1 to be handled by signalHandler
    signal(SIGUSR1, signalhandler);
    signal(SIGINT, handleExit);

    // Display the PID of the process
    // to make easier the use of kill command
    displayProcessPID();

    // Call the work thread
    // Thread used in order to process the signalhandler work
    pthread_t signalHandlerProcessThread;
    pthread_create(&signalHandlerProcessThread, NULL, signalhandler_work, NULL);

    // Simulate a work of 10 seconds
    // to let the time for user to send signal
    // from terminal
    do_work(15000);

    // Stop process
    processRunning = 0;

    // Wait for signalHandlerProcessThread to terminate
    pthread_join(signalHandlerProcessThread, NULL);

    return 0;
}
