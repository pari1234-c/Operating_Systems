#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();   // create child process

    if (pid < 0) {
        // error
        printf("Fork failed\n");
    }
    else if (pid == 0) {
        // child process
        printf("Child Process:\n");
        printf("PID = %d\n", getpid());
        printf("Parent PID = %d\n", getppid());
    }
    else {
        // parent process
        printf("Parent Process:\n");
        printf("PID = %d\n", getpid());
        printf("Child PID = %d\n", pid);
    }

    return 0;
}
