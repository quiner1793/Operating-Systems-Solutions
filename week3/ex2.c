#include <stdio.h>

void swap(int* first, int* second){
    int temp = *first;
    *first = *second;
    *second = temp;
}

void bubble_sort(int* arr, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}

int main(){
    int arr[] = {5, 4, 3, 2, 1};
    bubble_sort(arr, 5);

    printf("Sorted array:\n");
    for (int i = 0; i < 5; i++)
        printf("%d ", arr[i]);

    return 0;
}