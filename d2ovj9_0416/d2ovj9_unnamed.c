/*
Forrasok:
Dr. Vadasz Denes: Operacios rendszerek
Kay A. Robbins, Steven Robbins: UNIX Systems Programming
www.man7.org
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int fd[2];
    if(pipe(fd) == -1){
        printf("Hiba a pipe letrehozasa kozben.\n");
        return 1;
    }

    int pid = fork();
    if(pid == -1){
        printf("Hiba a forkolas kozben\n");
        return 2;
    }

    if(pid == 0){
        //child
        close(fd[0]);
        char str[] = "HA D2OVJ9";

        if(write(fd[1], str, sizeof(str)) == -1){
            printf("Hiba a pipe-ra iras kozben\n");
            return 3;
        }
        close(fd[1]);
    } else {
        //parent
        close(fd[1]);
        char str[20];
             
        read(fd[0], str, sizeof(str)); 
   
        printf("Olvasas eredmenye: %s\n", str);
        close(fd[0]);
        wait(NULL);
    }
    
    return 0;
}
