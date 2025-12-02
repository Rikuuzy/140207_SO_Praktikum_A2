#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    execv("/bin/echo",   /* program yang dimuat – hanya full path */
          &argv[0]);     /* argumen dikirim dari command line */

    printf("EXEC Failed\n");  /* Baris ini akan tercetak saat terjadi kesalahan */
    return 0;
}

