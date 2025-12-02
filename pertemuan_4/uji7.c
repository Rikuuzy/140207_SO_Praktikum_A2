#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    int howmany, status, whichone, child1, child2;

    /* Parent melahirkan child pertama */
    if ((child1 = fork()) == 0)
    {
        printf("Hi, I am the first child, my ID is %d, and my parent ID is %d\n",
               getpid(), getppid());
        sleep(10);   /* ubah angka ini untuk pengamatan hasil berbeda */
        printf("\nexiting first child\n");
        exit(0);
    }
    else if (child1 == -1)
    {
        perror("1st fork: something went wrong\n");
        exit(1);
    }

    /* Parent melahirkan child kedua */
    if ((child2 = fork()) == 0)
    {
        printf("Hi, I am the second child, my ID is %d, and my parent ID is %d\n",
               getpid(), getppid());
        sleep(5);    /* ubah angka ini untuk pengamatan hasil berbeda */
        printf("\nexiting second child\n");
        exit(0);
    }
    else if (child2 == -1)
    {
        perror("2nd fork: something went wrong\n");
        exit(1);
    }

    printf("\nThis is parent, my ID is %d\n", getpid());

    howmany = 0;
    while (howmany < 2)    /* Parent menunggu kedua child */
    {
        whichone = wait(&status);
        howmany++;

        printf("\nwhichone id = %d\n", whichone);
        printf("child1 id = %d\n", child1);
        printf("child2 id = %d\n", child2);

        if (whichone == child1)
            printf("First child exited\n");
        else if (whichone == child2)
            printf("Second child exited\n");
        else
            printf("Not child exited (unexpected)\n");

        if ((status & 0xFFFF) == 0)
            printf("correctly\n");
        else
            printf("uncorrectly\n");
    }

    printf("\nParent terminated\n");
    return 0;
}

