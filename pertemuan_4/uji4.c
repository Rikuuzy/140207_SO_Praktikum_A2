#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    execvp("echo",       /* program yang dimuat – PATH dicari */
           &argv[0]);    /* argumen dikirim dari command line */

    printf("EXEC Failed\n");  /* Baris ini akan tercetak saat terdapat kesalahan */
    return 0;
}

