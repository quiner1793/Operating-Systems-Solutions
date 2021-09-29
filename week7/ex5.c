# include <stdio.h>
#include "stdlib.h"
#define SIZE 100

int main () {
    char** s = (char **)malloc(sizeof((char *) malloc(sizeof(char) * SIZE)) * SIZE); // Analogue char* s[SIZE];

    char foo[] = "Hello World";
    *s = foo;
    printf ("s is %d\n", s);
    s[0] = foo;
    printf ("s [0] is %s\n", s[0]);
    return (0);
}