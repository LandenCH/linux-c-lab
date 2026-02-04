#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child exiting. PID=%d\n", getpid());
        exit(0);
    } else {
        printf("Parent alive. Child PID=%d\n", pid);
        printf("Sleeping for 60 seconds...\n");
        sleep(60);   // long sleep, no wait()
    }

    return 0;
}
