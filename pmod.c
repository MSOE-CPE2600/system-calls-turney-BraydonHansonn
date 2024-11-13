/**********************************************************
* Filename: pmod.c
* Section Num: 121
* Author: Braydon Hanson
* Date: 11/12/2024
***********************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {

    // Modify the process priority by reducing it (increase nice value by 10)
    nice(10);
    // Sleep for 1,837,272,638 nanoseconds (~1.837 seconds)
    struct timespec ts;
    ts.tv_sec = 1;  // 1 second
    ts.tv_nsec = 837272638;  // 837,272,638 nanoseconds

    nanosleep(&ts, NULL);

    // Print a goodbye message and exit
    printf("Goodbye!\n");

    return 0;
}
