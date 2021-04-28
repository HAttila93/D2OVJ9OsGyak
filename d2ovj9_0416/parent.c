/*
Forras:
Dr. Vadasz Denes: Operacios rendszerek
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    int pid = fork();
    char *args[] = {NULL};
    
    
    
    if(pid == 0) {
        execv("./child",args);
    } else {
        wait(NULL);
        printf("A gyermek processz lefutott.\n");
    }

    
    return 0;
}
