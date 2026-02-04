#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        execlp("wc", "wc", "-l", NULL);
    } else {
        close(fd[0]);
        write(fd[1], "one\ntwo\nthree\n", 14);
        close(fd[1]);
        wait(NULL);
    }
    return 0;
}
