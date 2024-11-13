/**********************************************************
* Filename: info.c
* Section Num: 121
* Author: Braydon Hanson
* Date: 11/12/2024
***********************************************************/

#include <stdio.h>
#include <time.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main(int argc, char* argv[]) {
    //time of day in nanoseconds

    struct timespec ts;

    if (clock_gettime(CLOCK_REALTIME, &ts) == 0) {
        printf("Time of Day in ns: %ld\n", ts.tv_sec * 1000000000L + ts.tv_nsec);
    } else {
        perror("clock_gettime");
    }

    // Systems network name
    char hostname[256];
    if (gethostname(hostname, sizeof(hostname)) == 0) {
        printf("System Network's Name: %s\n", hostname);
    } else {
        perror("gethostname");
    }

    // Operating system name, release, version, hardware type
    struct utsname uts;
    if (uname(&uts) == 0) {
        printf("Operating System Name: %s\n", uts.sysname);
        printf("Operating System Release: %s\n", uts.release);
        printf("Operating System Version: %s\n", uts.version);
        printf("System Hardware Type: %s\n", uts.machine);
    } else {
        perror("uname");
    }

    // Number of CPUs
    int num_cpus = get_nprocs();
    if(num_cpus != 0) {
        printf("Number of CPU's: %d\n", num_cpus);
    }

    // Total and free memory in bytes
    long page_size = getpagesize();
    long total_pages = sysconf(_SC_PHYS_PAGES);
    long free_pages = sysconf(_SC_AVPHYS_PAGES);

    long total_memory = total_pages * page_size;
    long free_memory = free_pages * page_size;

    if(total_memory != 0) {
        printf("Total Physical Memory (bytes): %ld\n", total_memory);
    }
    if(free_memory != 0) {
        printf("Total Free Memory (bytes): %ld\n", free_memory);
    }

    return 0;
}
