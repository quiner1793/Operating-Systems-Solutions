#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int first;
    float second;
    double third;

    first = INT_MAX;
    second = FLT_MAX;
    third = DBL_MAX;

    printf("Integer = %d, size = %d\n", first, sizeof(first));
    printf("Float = %f, size = %d\n", second, sizeof(second));
    printf("Double = %lf, size = %d\n", third, sizeof(third));

    return 0;
}
