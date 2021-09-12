#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    int pid = fork();

    if (pid > 0){
        printf("Hello from parent [PID %d]\n", pid);
    } else if (pid == 0){
        printf("Hello from child [PID %d]\n", pid);
    } else {
        return -1;
    }

    return 0;
}