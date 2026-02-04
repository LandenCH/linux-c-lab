#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child: PID=%d, PPID=%d\n", getpid(), getppid());
        sleep(1);
        exit(42);
    } else {
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            printf("Parent: child exited with %d\n", WEXITSTATUS(status));
        }
    }
    return 0;
}
