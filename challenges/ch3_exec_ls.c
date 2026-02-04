#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main() {
    if (fork() == 0) {
        execlp("ls", "ls", "-la", NULL);
    } else {
        wait(NULL);
        printf("ls finished\n");
    }
    return 0;
}
