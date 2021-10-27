#ifndef INTRODUCTION_HEADER
#define INTRODUCTION_HEADER

// Number of iteration needed to simulate a task of 1s (in ms)
#define DO_WORK_TIME_1S_MS 800000

#include "utils.h"

/**
 * @brief Simulation of work on CPU during x ms
 * 
 * @param duration Task's duration
 * @return void* 
 */
void* do_work(long unsigned int duration) {
    duration = duration * DO_WORK_TIME_1S_MS;
    
    while (duration-- > 0 && processRunning)
        asm volatile ("nop");
}

#endif // INTRODUCTION_HEADER