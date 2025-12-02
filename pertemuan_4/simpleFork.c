#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
    // process id
    int pid, i, endvalue;

    endvalue = 1000;
    printf("calling fork()\n");

    pid = fork();   // create new process

    // check if fork worked
    if (pid < 0)
    {
        printf("Fork failed\n");
        exit(0);
    }
    else if (pid == 0)
    {
        // child process
        for (i = 0; i < endvalue; i++)
        {
            printf("Child\n");
            fflush(stdout);
        }
    }
    else
    {
        // parent process
        wait(NULL);   // wait for child to finish
        for (i = 0; i < endvalue; i++)
        {
            printf("Parent\n");
            fflush(stdout);
        }
        printf("Child Complete\n");
        exit(0);
    }
}

