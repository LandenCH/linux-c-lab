#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    int p[2];
    pipe(p);

    if (fork() == 0) {
        dup2(p[1], STDOUT_FILENO);
        close(p[0]);
        execlp("ls", "ls", NULL);
    }

    if (fork() == 0) {
        dup2(p[0], STDIN_FILENO);
        close(p[1]);
        execlp("grep", "grep", ".c", NULL);
    }

    close(p[0]);
    close(p[1]);
    wait(NULL);
    wait(NULL);
    return 0;
}
