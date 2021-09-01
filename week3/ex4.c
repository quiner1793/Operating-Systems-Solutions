#include <stdio.h>

void swap(int* first, int* second){
    int temp = *first;
    *first = *second;
    *second = temp;
}

int partitioning(int* arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++){
        if (arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    i++;
    swap(&arr[i], &arr[high]);
    return i;
}

void quicksort(int* arr, int low, int high){
    if (low < high){
        int index = partitioning(arr, low, high);

        quicksort(arr, low, index-1);
        quicksort(arr, index+1, high);
    }
}

void printArr(int* arr, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", *(arr+i));
    }
    printf("\n");
}

int main(){
    int arr[] = {10, 12, 15, 2, 6, 33, 14, 10};
    int arrSize = 8;

    quicksort(arr, 0, arrSize - 1);

    printArr(arr, arrSize);
    
    return 0;
}

