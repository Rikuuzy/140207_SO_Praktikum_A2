// Child Program
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    while (1)
    {
        printf("Child\n");
        fflush(stdout);
	sleep(1);
    }
}

