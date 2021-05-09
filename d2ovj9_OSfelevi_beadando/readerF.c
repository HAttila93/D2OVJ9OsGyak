#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
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
	int shmid;
	key_t key;
	int shmflg;
    char *data;
   

	key = SHMKEY;
	shmflg = 0;

    sem_unlink(SEM_PRODUCER);
    sem_unlink(SEM_CONSUMER);

	sem_t *sem_producer = sem_open(SEM_PRODUCER, O_CREAT, 0660, 0);
    if(sem_producer == SEM_FAILED){
        perror("semopen/producer");
    }
	sem_t *sem_consumer = sem_open(SEM_CONSUMER, O_CREAT, 0660, 1);
    if(sem_producer == SEM_FAILED){
        perror("semopen/consumer");
    }
	if((shmid = shmget(key, SIZE, shmflg)) < 0){
		printf("Nincs meg a szegmens!\n");
		}
	
    data = shmat(shmid, NULL, 0);
    
    while (1){
        sem_wait(sem_producer);    	
        if(strlen(data) > 0){
    		printf("Olvasom: %s\n", data);
    	}
        sem_post(sem_consumer);
        
    }

    sem_close(sem_consumer);
    sem_close(sem_producer);


	return 0;
}
