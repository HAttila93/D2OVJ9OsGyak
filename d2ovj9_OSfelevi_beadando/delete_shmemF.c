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
    
    shmid = shmget(key, SIZE, shmflg);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}