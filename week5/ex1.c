#include "stdio.h"
#include "stdint.h"
#include "pthread.h"

int n_threads = 20;
int flag_interest[20];
int turn;

void* myThread(void* args){
    while ((int) args != turn && !flag_interest[(int) args]) {}
    printf(">>Hello from myThread #%d\n", args);
    turn++;
    flag_interest[(int) args] = 0;
    pthread_exit(NULL);
}

int main(){
    for (int i = 0; i < n_threads; i++){
        flag_interest[i] = 0;
    }
    turn = 0;

    pthread_t thread;

    for (int i = 0; i < n_threads; i++){
        if (pthread_create(&thread, NULL, myThread, i)){
            printf(" >> ERROR IN CREATING Thread!\n");
            pthread_exit(NULL);
            return 1;
        } else{
            printf(" >>Thread #%d created!\n", i);
            flag_interest[i] = 1;
            while (flag_interest[i]) {}
        }
    }

    return 0;
}