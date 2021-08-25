#include <stdio.h>

void swap_numbers(int* first, int* second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

int main(){
    printf("Enter first number:\n");
    int first;
    scanf("%d", &first);

    printf("Enter second number:\n");
    int second;
    scanf("%d", &second);

    printf("Number before swap: first - %d, second - %d\n", first, second);

    swap_numbers(&first, &second);

    printf("Number after swap: first - %d, second - %d", first, second);

    return 0;
}