#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Hello from child (PID=%d, PPID=%d)\n", getpid(), getppid());
        sleep(2);
        exit(7);
    } else {
        int status;
        waitpid(pid, &status, 0);
        printf("child %d exited with status %d\n", pid, WEXITSTATUS(status));
    }
    return 0;
}
