#include "stdio.h"
#define NUMBER_PR 32

struct process_robin{
    int process_num;
    int arrival_time;
    int finish_time;
    int burst_time;
    int proceeded_time;
    int finished;
};

void swap(struct process_robin* first, struct process_robin* second){
    struct process_robin temp;
    temp = *first;
    *first = *second;
    *second = temp;
}

int main(){
    struct process_robin processes[NUMBER_PR];
    int n;
    printf("Enter number of processes:");
    scanf("%d", &n);

    if (n >= NUMBER_PR || n < 0){
        printf("\nIncorrect number of processes\n");
        return 1;
    }

    printf("Enter Arrival time and Burst time for each process_robin:\n");

    for (int i = 0; i < n; i++){
        int arr;
        printf("Arrival time of process_robin[%d]:", i);
        scanf("%d", &arr);
        int bur;
        printf("Burst time of process_robin[%d]:", i);
        scanf("%d", &bur);

        processes[i].arrival_time = arr;
        processes[i].burst_time = bur;
        processes[i].process_num = i+1;
        processes[i].finished = 0;
        processes[i].proceeded_time = 0;
    }

    int time_quantum;
    printf("Enter time quantum:");
    scanf("%d", &time_quantum);

    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (processes[i].arrival_time > processes[j].arrival_time){
                swap(&processes[i], &processes[j]);
            }
        }
    }

    int processes_to_proceed = 1;
    int current_time = processes[0].arrival_time;
    int TAT_sum = 0;
    int WT_sum = 0;

    while (processes_to_proceed){
        processes_to_proceed = 0;

        for (int i = 0; i < n; i++){
            if (!processes[i].finished){
                if (processes[i].arrival_time <= current_time) {
                    processes_to_proceed++;
                    if (processes[i].burst_time - processes[i].proceeded_time < time_quantum){
                        int p_time = processes[i].burst_time - processes[i].proceeded_time;
                        processes[i].proceeded_time += p_time;
                        current_time += p_time;
                    } else{
                        processes[i].proceeded_time += time_quantum;
                        current_time += time_quantum;
                    }
                }
                if (processes[i].proceeded_time >= processes[i].burst_time) {
                    processes[i].finished = 1;
                    processes[i].finish_time = current_time;
                }
            }
        }
    }

    printf("P#\tAT\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++){
        int AT = processes[i].arrival_time;
        int BT = processes[i].burst_time;
        int CT = processes[i].finish_time;
        int TAT = CT - AT;
        int WT = TAT - BT;

        TAT_sum += TAT;
        WT_sum += WT;

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", processes[i].process_num, AT, BT, CT, TAT, WT);
    }

    printf("\nAverage Turnaround Time = %5f\n", TAT_sum / (float) n);
    printf("Average Waiting Time = %5f\n", WT_sum / (float) n);

    return 0;
}