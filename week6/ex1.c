#include "stdio.h"
#define NUMBER_PR 32

struct process{
    int process_num;
    int arrival_time;
    int burst_time;
    int finished;
};

void swap(struct process* first, struct process* second){
    struct process temp;
    temp = *first;
    *first = *second;
    *second = temp;
}

int main(){
    struct process processes[NUMBER_PR];
    int n;
    printf("Enter number of processes:");
    scanf("%d", &n);

    if (n >= NUMBER_PR || n < 0){
        printf("\nIncorrect number of processes\n");
        return 1;
    }

    printf("Enter Arrival time and Burst time for each process:\n");

    for (int i = 0; i < n; i++){
        int arr;
        printf("Arrival time of process[%d]:", i);
        scanf("%d", &arr);
        int bur;
        printf("Burst time of process[%d]:", i);
        scanf("%d", &bur);

        processes[i].arrival_time = arr;
        processes[i].burst_time = bur;
        processes[i].process_num = i+1;
    }

    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (processes[i].arrival_time > processes[j].arrival_time){
                swap(&processes[i], &processes[j]);
            }
        }
    }

    printf("P#\tAT\tBT\tCT\tTAT\tWT\n");

    int current_time = processes[0].arrival_time;
    int TAT_sum = 0;
    int WT_sum = 0;

    for (int i = 0; i < n; i++){
        int AT = processes[i].arrival_time;
        int BT = processes[i].burst_time;
        int CT = current_time + BT;
        int TAT = CT - AT;
        int WT = TAT - BT;

        TAT_sum += TAT;
        WT_sum += WT;

        current_time = CT;

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", processes[i].process_num, AT, BT, CT, TAT, WT);
    }

    printf("\nAverage Turnaround Time = %5f\n", TAT_sum / (float) n);
    printf("Average Waiting Time = %5f\n", WT_sum / (float) n);

    return 0;
}