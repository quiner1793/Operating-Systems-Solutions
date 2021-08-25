#include <stdio.h>
#include <string.h>

int main(){
    char* input[128];

    printf("Enter a string:\n");
    fgets(input, 128, stdin);

    printf("%s\n", strrev(input));

    return 0;
}