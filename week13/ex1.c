#include "stdio.h"
#define FILE_NAME "input_ok.txt"
#define N_TYPES 3
#define N_PROC 5

int main(){
    int E[N_TYPES];
    int A[N_TYPES];
    int C[N_PROC][N_TYPES];
    int R[N_PROC][N_TYPES];
    int is_deallocated[N_PROC];

    for (int i = 0; i < N_PROC; i++){
        is_deallocated[i] = 0;
    }

    FILE* file = fopen(FILE_NAME, "r");
    for (int i = 0; i < N_TYPES; i++){
        fscanf(file, "%i", E+i);
    }
    for (int i = 0; i < N_TYPES; i++){
        fscanf(file, "%i", A+i);
    }
    for(int i = 0; i < N_PROC; i++){
        for(int j = 0; j < N_TYPES; j++){
            fscanf(file, "%i", &C[i][j]);
        }
    }
    for(int i = 0; i < N_PROC; i++){
        for(int j = 0; j < N_TYPES; j++){
            fscanf(file, "%i", &R[i][j]);
         }
    }
    fclose(file);

    int flag = 1;
    while (flag){
        flag = 0;
        for (int indx = 0; indx < N_PROC; indx++) {
            if (!is_deallocated[indx]) {
                int local_flag = 1;
                for (int i = 0; i < N_TYPES; i++) {
                    if (A[i] + C[indx][i] < R[indx][i])
                        local_flag = 0;
                }
                if (local_flag) {
                    flag = 1;
                    is_deallocated[indx] = 1;
                    for (int i = 0; i < N_TYPES; i++) {
                        A[i] += C[indx][i];
                    }
                }
            }
        }
    }

    for (int i = 0; i < N_PROC; i++){
        if (!is_deallocated[i]){
            printf("Deadlock in process #%i\n", i);
            return 0;
        }
    }

    printf("No deadlock\n");

    return 0;
}