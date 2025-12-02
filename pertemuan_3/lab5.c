#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    int forkresult;

    printf("%d: I am the parent. Remember my number!\n", getpid());
    printf("%d: I am now going to fork ... \n", getpid());

    forkresult = fork();

    printf("###############################\n");

    if (forkresult != 0) {
        /* proses parent akan mengeksekusi kode di bawah */
        printf("%d: My child's pid is %d\n", getpid(), forkresult);
    }
    else { 
        /* hasil fork == 0 → proses child */
        printf("%d: Hi! I am the child.\n", getpid());
    }

    printf("%d: like father like son.\n", getpid());

    return 0;
}

