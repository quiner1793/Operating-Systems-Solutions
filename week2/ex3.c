#include <stdio.h>

void print_figure(int n)
{
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n-i-1; j++){
            printf(" ");
        }
        for(int j = n-i; j<=n+i; j++){
            printf("*");
        }
        for(int j = n+i; j<2*n; j++){
            printf(" ");
        }
        printf("\n");
    }
}

int main(){
    int n;

    printf("Enter n:");
    scanf("%d", &n);

    print_figure(n);

    return 1;
}