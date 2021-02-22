#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *hello_Word(void *tid){
    printf("Hello Word. Esta é a thread %d\n", (int)(size_t)tid);
    //sleep(((int)(size_t)tid+1)*2);
    pthread_exit(NULL);
}

void *regra_Trapezio(void *tid){
    
    h = (b-a)/n;
    area_total = (f(a) + f(b)) / 2;
    
    for(int i = 1; i < n; i ++){
        x_i = a + i * h;
        area_total += f(x_i);
    }
    
    area_total += h * area_total;
}

int main(int argc, char *argv[]){
    
    int status,numthreads, numtrapezios, i;
    void *thread_return;

    printf("Digite o numero de threads: ");
    scanf("%d", &numthreads);

    printf("Digite o numero de Trapezios: ");
    scanf("%d", &numtrapezios);
    
    pthread_t threads[numthreads];
    
    for(i=0; i<numthreads; i++){
        printf("Processo principal criando thread#%d\n", i);
        status = pthread_create(&threads[i], NULL, hello_Word, (void*)(size_t) i);

        if(status != 0){
            printf("Erro na criaçao da thread. Codigo de Erro:%d\n", status);
            return 1;
        }

    }

    for(i=0; i<numthreads; i++){
        printf("Esperando Thread %d finalizar....\n", i);
        pthread_join(threads[i], &thread_return);
        printf("Thread %d finalizada\n", i);
    }

    printf("Processo vai finalizar\n");

}
