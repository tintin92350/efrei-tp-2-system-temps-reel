/**
 * @file 3-taches-sporadiques.c
 * @author Quentin RODIC (quentin.rodic@efrei.net)
 * @brief Question 3 - Tâches Sporadiques
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

#include "1-introduction.h"

#include "utils.h"

/**
 * @brief Handling signals
 * 
 * @param signum Signal
 */
void signalhandler(int signum) {
    printf("Handling signal : %d\n", signum);

    // Simulate a hard work of 5 seconds
    do_work(5000);
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
 * Exemple of output:
 * $ process pid      8488
 * $ Handling signal : 10
 * $ Handling signal : 10
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char** argv) {

    // Register SIGUSR1 to be handled by signalHandler
    signal(SIGUSR1, signalhandler);

    // Display the PID of the process
    // to make easier the use of kill command
    displayProcessPID();

    // Simulate a work of 10 seconds
    // to let the time for user to send signal
    // from terminal 
    do_work(10000);

    return 0;
}
