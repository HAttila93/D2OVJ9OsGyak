#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMKEY 123456L
#define SIZE 512

int main(int argc, char const *argv[])
{

    int shmid;
    key_t key;
    int shmflg;

    key = SHMKEY;
    shmflg = 0;
    
    if((shmid = shmget(key, SIZE, shmflg)) < 0){
        printf("Nincs meg ilyen szegmens, keszitsuk el!\n");
        shmflg = 0666 | IPC_CREAT;
        if((shmid = shmget(key, SIZE, shmflg)) < 0){
           perror("Az shmget system-call sikertelen!\n");
           exit(-1); 
        }
    } else {
        printf("A szegmens mar letezik!\n");    
    }

    printf("A szegmens azonositoja: %d\n", shmid);

    return 0;
}