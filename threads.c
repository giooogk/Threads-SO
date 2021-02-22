#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *hello_Word(void *tid){
    printf("Hello Word. Esta é a thread %d\n", (int)(size_t)tid);
    //sleep(((int)(size_t)tid+1)*2);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]){
    
    pthread_t thread;
    int status;
    void *thread_return;

    printf("Processo principal criando thread\n");
    status = pthread_create(&thread, NULL, hello_Word, 0);
    
    if(status!=0){
        printf("Erro na criação da thread.  Codigo de Erro%d\n", status);
        return 1;
    }

    printf("Esperando Thread finalizar....\n");
    pthread_join(thread, &thread_return);
    printf("Thread finalizada\n");

    printf("processo pai vai finalizar\n");

    return 0;
}
