#include <unistd.h>
#include <sys/wait.h>

int main() {
    if (fork() == 0)
        execl("/bin/echo", "echo", "one", "two", NULL);

    if (fork() == 0) {
        char *args[] = {"echo", "one", "two", NULL};
        execv("/bin/echo", args);
    }

    wait(NULL);
    wait(NULL);
    return 0;
}
