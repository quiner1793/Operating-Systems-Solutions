#include "stdio.h"
#include "stdint.h"
#include "pthread.h"
#include <unistd.h>
#include "time.h"

#define BUFFER_SIZE 9

int buf_count;
int producer_sleep;
int consumer_sleep;
int myBuffer[BUFFER_SIZE];

_Noreturn void* producer(void* args){
    while (1){
        if (producer_sleep)
            continue;

        if (buf_count == BUFFER_SIZE){
            producer_sleep = 1;
            consumer_sleep = 0;
            continue;
        }

        time_t res = time(NULL);
        if (res % 5 == 0){
            myBuffer[buf_count] = res % 60;
            buf_count++;
        }
    }
}

_Noreturn void* consumer(void* args){
    int myNum;
    while (1){
        if (consumer_sleep)
            continue;

        if (buf_count == 0){
            consumer_sleep = 1;
            producer_sleep = 0;
            continue;
        }

        myNum = myBuffer[buf_count-1];
        buf_count--;

        if (myNum == 10){
            printf("var: %d, buf_count: %d\n", myNum, buf_count);
        }
    }
}

int main(){
    buf_count = 0;
    producer_sleep = 0;
    consumer_sleep = 1;

    pthread_t producer_t;
    pthread_t consumer_t;

    if (pthread_create(&producer_t, NULL, producer, NULL)){
        printf(" >> ERROR IN CREATING Thread!\n");
        pthread_exit(NULL);
        return 1;
    }

    if (pthread_create(&consumer_t, NULL, consumer, NULL)){
        printf(" >> ERROR IN CREATING Thread!\n");
        pthread_exit(NULL);
        return 1;
    }

    sleep(120000);

    return 0;
}