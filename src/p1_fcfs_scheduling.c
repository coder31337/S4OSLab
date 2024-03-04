#include <stdio.h>
#define MAX_SIZE 100

int main() {
    int pids[MAX_SIZE], arrival_times[MAX_SIZE], burst_times[MAX_SIZE],
        completion_times[MAX_SIZE], waiting_times[MAX_SIZE],
        turnaround_times[MAX_SIZE];
    int n, i, j, temp, total_wt_time, total_ta_time;
    float avg_wt_time, avg_ta_time;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);
        printf("Enter PID: ");
        scanf("%d", &pids[i]);
        printf("Enter burst time: ");
        scanf("%d", &burst_times[i]);
        printf("Enter arrival time: ");
        scanf("%d", &arrival_times[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arrival_times[j] > arrival_times[j + 1]) {
                temp = pids[j];
                pids[j] = pids[j + 1];
                pids[j + 1] = temp;

                temp = arrival_times[j];
                arrival_times[j] = arrival_times[j + 1];
                arrival_times[j + 1] = temp;

                temp = burst_times[j];
                burst_times[j] = burst_times[j + 1];
                burst_times[j + 1] = temp;
            }
        }
    }

    completion_times[0] = burst_times[0];
    for (i = 1; i < n; i++)
        completion_times[i] = completion_times[i - 1] + burst_times[i];

    total_ta_time = total_wt_time = 0;
    for (i = 0; i < n; i++) {
        turnaround_times[i] = completion_times[i] - arrival_times[i];
        waiting_times[i] = turnaround_times[i] - burst_times[i];
        total_wt_time += waiting_times[i];
        total_ta_time += turnaround_times[i];
    }
    avg_wt_time = (float)total_wt_time / n;
    avg_ta_time = (float)total_ta_time / n;

    printf("\nThe execution order is\n");
    printf("PID\tArrivalTime\tBurstTime\tCompletionTime\tWaitingTime\tTurnaroundTime\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pids[i], arrival_times[i],
               burst_times[i], completion_times[i], waiting_times[i],
               turnaround_times[i]);
    }
    printf("\nAverage waiting time = %0.2f\n", avg_wt_time);
    printf("Average turnaround time = %0.2f\n", avg_ta_time);

    return 0;
}
