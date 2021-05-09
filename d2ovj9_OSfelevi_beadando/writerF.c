#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <semaphore.h>

#define SHMKEY 123456L
#define SIZE 512
#define SEM_PRODUCER "/producer"
#define SEM_CONSUMER "/consumer"

int main(int argc, char const *argv[])
{
	int shmid, shmflg;
	key_t key = SHMKEY;
	shmflg = 0;

    char *data;

    sem_t *sem_producer = sem_open(SEM_PRODUCER, O_EXCL);
    sem_t *sem_consumer = sem_open(SEM_CONSUMER, O_EXCL);

    
    if((shmid = shmget(key, SIZE, shmflg)) < 0){
        printf("Nincs meg a szegmens!\n");
    }
    
    data = shmat(shmid, NULL, 0);
    printf("Beleirok\n");    
    for(int i = 0; i < 5; i++){
        sem_wait(sem_consumer);
        strncpy(data, argv[1], 10);
        sem_post(sem_producer);
    }    
    
    printf("Beleirtam: %s\n", argv[1]);

    sem_close(sem_producer);
    sem_close(sem_consumer);

	return 0;
}
