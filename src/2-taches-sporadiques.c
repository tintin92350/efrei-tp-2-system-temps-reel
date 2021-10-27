/**
 * @file 2-taches-sporadiques.c
 * @author Quentin RODIC (quentin.rodic@efrei.net)
 * @brief Question 2 - Tâches Sporadiques
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
}

/**
 * @brief Main entry point of the program.
 * Register a signal handler and wait for 10 seconds
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
