#ifndef UTILS_HEADER
#define UTILS_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * @brief Display the current process PID in the standard output
 * 
 */
void displayProcessPID()
{
    printf("process pid \t %d\n", getpid());
}

// Is process running ?
// global variable to be used in all programs with infinity loop
int processRunning = 1;

void handleExit(int signum) {
    processRunning = 0;
}

#endif // UTILS_HEADER