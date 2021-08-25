#include <stdio.h>

void first_print(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        for (int j = i; j < n; j++)
        {
            printf(" ");
        }
        printf("\n");
    }
}

void second_print(int n)
{
    int i;
     for (i = 0; i < n/2; i++)
     {
         for (int j = 0; j <= i; j++)
         {
             printf("*");
         }
         for (int j = i; j < n; j++)
         {
             printf(" ");
         }
         printf("\n");
     }

     for ( ; i < n; i++)
     {
        for (int j = 0; j < n - i; j++)
        {
            printf("*");
        }
        for (int j = 0; j < i; j++)
        {
            printf(" ");
        }
        printf("\n");
     }
}

void third_print(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int main()
{
    int n;

    printf("Enter n:");
    scanf("%d", &n);

    int f_type;
    printf("Choose figure type:");
    scanf("%d", &f_type);

    switch (f_type) {
        case 1:
            first_print(n);
            break;
        case 2:
            second_print(n);
            break;
        case 3:
            third_print(n);
            break;
        default:
            printf("Invalid figure type");
    }

    return 0;
}