/**********************************************************
* Filename: pinfo.c
* Section Num: 121
* Author: Braydon Hanson
* Date: 11/12/2024
***********************************************************/
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>          
#include <sys/resource.h>    
#include <sched.h>            
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int processID = getpid();
    if (argc >= 2 && argv != NULL) {
        processID = atoi(argv[1]);
    }

    printf("Process ID          : %d\n", processID);
    printf("Priority of Process : %d\n", getpriority(PRIO_PROCESS, processID));

    int policy = sched_getscheduler(processID);
    printf("Scheduling Policy   : ");
    switch (policy) {
        case SCHED_OTHER:
            printf("SCHED_OTHER\n");  // Default time-sharing policy
            break;
        case SCHED_FIFO:
            printf("SCHED_FIFO\n");    // First-in, first-out real-time policy
            break;
        case SCHED_RR:
            printf("SCHED_RR\n");      // Round-robin real-time policy
            break;
        case SCHED_BATCH:
            printf("SCHED_BATCH\n");   // Batch processing policy for CPU-intensive jobs
            break;
        case SCHED_IDLE:
            printf("SCHED_IDLE\n");    // Very low priority for idle processes
            break;
        case SCHED_DEADLINE:
            printf("SCHED_DEADLINE\n"); // Deadline scheduling (Linux-specific)
            break;
        default:
            printf("UNKNOWN\n");       // Unknown or unsupported policy
            break;
    }

    return 0;
}
