#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int p[2];
    pipe(p);

    if (fork() == 0) {
        dup2(p[1], STDOUT_FILENO);
        execlp("ls", "ls", NULL);
    }

    if (fork() == 0) {
        dup2(p[0], STDIN_FILENO);
        execlp("grep", "grep", argv[1], NULL);
    }

    close(p[0]);
    close(p[1]);
    wait(NULL);
    wait(NULL);
    return 0;
}
