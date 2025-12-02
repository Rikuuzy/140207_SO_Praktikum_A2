// Parent Program
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <error.h>
#include <signal.h>
#include <errno.h>

int main(void)
{
    pid_t pid;

    if ((pid = fork()) < 0)
    {
        // probably out of processes
        exit(1);
    }
    else if (pid == 0)
    {
        // in child, execute child program
        // use execl to run a shell and execute the child program
        execl("/bin/sh", "sh", "-c", "./child", (char *)0);

        // if execl fails
        perror("execl failed");
        exit(1);
    }

    while (1)
    {
        sleep(1);
        printf("Parent\n");
        fflush(stdout);
    }

    printf("end of program\n");
}

