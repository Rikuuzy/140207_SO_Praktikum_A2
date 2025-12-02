#include <stdio.h>
#include <unistd.h> /* Berisi prototype fork */

int main(void)
{
    printf("Hello World\n");

    fork();

    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("I am after forking\n");
    printf("\tI am process %d.\n", getpid());
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");

    return 0;
}

