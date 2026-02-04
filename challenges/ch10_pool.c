#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main() {
    int max = 2, running = 0;

    for (int i = 0; i < 5; i++) {
        while (running >= max) {
            wait(NULL);
            running--;
        }
        if (fork() == 0) {
            sleep(2);
            _exit(0);
        }
        running++;
    }

    while (running--)
        wait(NULL);

    return 0;
}
