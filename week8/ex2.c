#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"


int main(){
    int size = 1024*1024*10;
    for (int i = 0; i < 10; i++){
        int* mem = calloc(size / sizeof(int), sizeof(int)); // Allocate memory; free space decreases
        memset(mem, 0, size); // Filling up memory; Swapping number increases
        sleep(1);
    }
    printf("Finish allocation\n");

    return 0;
}