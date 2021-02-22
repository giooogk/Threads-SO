#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 10
#define BUFFER_SAFRA 3

int buffer_index = 0;

void* produtor(int* buffer){
   
    int count = 0;
    while(count < BUFFER_SAFRA){
        
        while (buffer_index == BUFFER_SIZE){
            
            //BUFFER ESTA CHEIO
            printf("PRODUTO: buffer está CHEIO. Indo dormir....\n");
            sleep(3);
        }
        
        //PRODUZINDO
        buffer[buffer_index] = buffer_index;
        printf("PRODUTOR(SAFRA=%d): trabalhando... produzindo: %d\n", count, buffer_index);
        
        buffer_index++;
        
        if(buffer_index == BUFFER_SIZE){
            count++;
        }
    } 

    pthread_exit(NULL);

}

void* consumirdor(int* buffer){
    
    int tmp, count = 0;

    //sleep(10);

    while (count < BUFFER_SAFRA){
        while(buffer_index == 0){
            //buffer esta vazio
            printf("CONSUMIDOR: buffer está VAZIO. Indo dormir.... \n");
            sleep(3);
        }

        //consumidor...
        tmp = buffer[buffer_index-1];
        printf("COSUMIDOR(SAFRA= %d): trabalhando... consumi: %d\n", count, tmp);
        
        buffer_index--;

        if(buffer_index == 0){
            count++;
        }
    }
    
    pthread_exit(NULL);
}

int main(){
    pthread_t p, c;
    int status, i;
    int *buffer = malloc(sizeof(int)*BUFFER_SIZE);
    status = pthread_create(&p, NULL, (void*)produtor, buffer);
    status = pthread_create(&c, NULL, (void*)consumirdor, buffer);
    pthread_join(p, NULL);
    pthread_join(c, NULL);
    printf("threads terminaram! Imprimindo o buffer:\n");
    printf("POSICAO | VALOR \n");
    for (i = 0; i < BUFFER_SIZE; i++){
        printf("BuFFER[%d]: %d\n", i, buffer[i]);
    }
       
    exit(EXIT_SUCCESS);
}