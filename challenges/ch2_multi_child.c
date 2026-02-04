#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int N = atoi(argv[1]);

    for (int i = 0; i < N; i++) {
        if (fork() == 0) {
            printf("Child %d exiting\n", i);
            exit(i + 1);
        }
    }

    for (int i = 0; i < N; i++) {
        int status;
        pid_t pid = wait(&status);
        printf("Parent: child %d exited with %d\n", pid, WEXITSTATUS(status));
    }
    return 0;
}

