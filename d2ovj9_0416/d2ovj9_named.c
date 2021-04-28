/*
Forrasok:
Dr. Vadasz Denes: Operacios rendszerek
Kay A. Robbins, Steven Robbins: UNIX Systems Programming
www.man7.org
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char const *argv[])
{

    char str[] = "Hegedus Attila";

    int fd;
    int pid = fork();
    if(pid == -1){
        printf("Hiba a forkolas kozben.\n");
        return 1;
    }

    if(pid == 0){
        //child
        fd = open("d2ovj9", O_WRONLY);
        
        if(write(fd, str, sizeof(str)) == -1){
            printf("Hiba a fifo-ba iras kozben\n");
            return 2;
        }    
        close(fd);

    } else {
        //parent
        if(mkfifo("d2ovj9", 0777) == -1){
            if(errno != EEXIST){
                printf("Hiba a fifo letrehozasa kozben\n");
                return 3;
            }
        }
        fd = open("d2ovj9", O_RDONLY);
        
        char str2[20];

        read(fd, str2, sizeof(str2));
        printf("Olvasas eredmenye: %s\n", str2);
        close(fd);
        wait(NULL);

    }

    return 0;
}

