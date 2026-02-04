#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        execlp("ls", "ls", "-l", NULL);
        perror("exec failed");
        exit(1);
    } else {
        wait(NULL);
        printf("Parent: exec demo finished\n");
    }
    return 0;
}

