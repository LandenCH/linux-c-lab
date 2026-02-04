#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    if (fork() == 0) {
        char *args[] = {"./worker", "hello", NULL};
        char *env[] = {"MYVAR=hello", NULL};
        execve("./worker", args, env);
    } else {
        wait(NULL);
    }
    return 0;
}
