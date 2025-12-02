#include <stdio.h>
#include <unistd.h>

int main()
{
    execlp("ls",          /* program yang dimuat – PATH dicari */
           "ls",          /* nama program yang akan dikirim ke argv[0] */
           "-l",          /* parameter pertama (argv[1]) */
           "-a",          /* parameter kedua (argv[2]) */
           NULL);         /* terminasi arg list */

    printf("EXEC Failed\n");   /* Baris ini akan tercetak saat terdapat kesalahan */
    return 0;
}

