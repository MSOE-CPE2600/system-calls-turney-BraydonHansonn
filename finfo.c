/**********************************************************
* Filename: finfo.c
* Section Num: 121
* Author: Braydon Hanson
* Date: 11/12/2024
***********************************************************/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char* argv[]) {
    int fd;
    if(argc > 1) {
        fd = open(argv[1], O_RDONLY);
    } else {
        printf("File not provided in command line\n");
        return 1;
    }
    if(fd == -1) {
        printf("File not found\n");
        return 1;
    }
    char buffer[128];
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);

    buffer[bytesRead] = '\0';  // Null-terminate the string
    printf("Read from File: %s\n", buffer);

    struct stat fileStat;
    stat(argv[1], &fileStat);

    // Owner permissions
    printf("Owner Permissions: ");
    if (fileStat.st_mode & S_IRUSR) printf("r"); // read
    if (fileStat.st_mode & S_IWUSR) printf("w"); // write
    if (fileStat.st_mode & S_IXUSR) printf("x"); // execute
    printf("\n");

    // User ID
    printf("User ID: %d\n", getuid());

    // File size in bytes
    printf("File Size: %ld bytes\n", fileStat.st_size);

    // Last modification time
    char modTime[100];
    struct tm *tm_info = localtime(&fileStat.st_mtime);
    strftime(modTime, sizeof(modTime), "%Y-%m-%d %H:%M:%S", tm_info);
    printf("Last Modification: %s\n", modTime);


    close(fd);
    return 0;
}
