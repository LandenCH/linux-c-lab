#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child exiting\n");
        exit(0);
    } else {
        sleep(10); // zombie exists here
        wait(NULL);
    }
    return 0;
}
