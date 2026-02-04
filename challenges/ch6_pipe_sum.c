#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        close(fd[1]);
        int x, sum = 0;
        while (read(fd[0], &x, sizeof(x)) > 0)
            sum += x;
        printf("Sum = %d\n", sum);
    } else {
        close(fd[0]);
        for (int i = 1; i <= 10; i++)
            write(fd[1], &i, sizeof(i));
        close(fd[1]);
        wait(NULL);
    }
    return 0;
}
