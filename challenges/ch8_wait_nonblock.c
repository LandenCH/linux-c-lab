#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main() {
    for (int i = 1; i <= 3; i++) {
        if (fork() == 0) {
            sleep(i);
            _exit(i);
        }
    }

    int status;
    while (waitpid(-1, &status, WNOHANG) >= 0) {
        usleep(200000);
    }
    return 0;
}
