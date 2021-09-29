#include "stdio.h"
#include "stdlib.h"

void* my_realloc(int* ptr, int new_size){
    if (ptr == NULL)
        return malloc(sizeof(int) * new_size);
    if (new_size == 0){
        free(ptr);
        return NULL;
    }

    int* temp = malloc(sizeof(int) * new_size);

    for (int i = 0; i < new_size; i++){
        temp[i] = ptr[i];
    }

    ptr = temp;
}


int main(){
    int n;
    printf("Enter original size of array:");
    scanf("%d", &n);

    int* arr = malloc(sizeof(int) * n);

    printf("Enter content of array:\n");

    for (int i = 0; i < n; i++){
        printf("Enter %d element:", i);
        scanf("%d", arr + i);
    }

    int new_n;
    printf("Enter new size of array:");
    scanf("%d", &new_n);

    my_realloc(arr, new_n);

    printf("Content of realloced array");

    for (int i = 0; i < new_n; i++){
        printf("\n%d element:%d", i, arr[i]);
    }


    return 0;
}