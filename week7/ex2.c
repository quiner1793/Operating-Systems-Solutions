#include "stdio.h"
#include "stdlib.h"

int main(){
    int n;
    printf("Enter size of array:");
    scanf("%d", &n);

    int* arr = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++){
        arr[i] = i;
    }

    for (int i = 0; i < n; i++){
        printf("Arr[%d]==%d\n", i, arr[i]);
    }

    free(arr);
    return 0;
}