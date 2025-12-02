#include <stdio.h>
#include <unistd.h>   /* untuk fork(), sleep(), getpid() */
#include <stdlib.h>   /* untuk exit() */

int main(void)
{
    int pid;

    pid = fork(); /* Duplikasi proses: child dan parent */

    if (pid != 0) {  
        /* Parent: tidak terminate dan tidak mengeksekusi wait() → child jadi zombie */
        while (1)
            sleep(100);  /* berhenti 100 detik berulang-ulang */
    }
    else {
        /* Child: langsung exit sehingga menjadi zombie */
        exit(42);  
    }

    return 0;
}

