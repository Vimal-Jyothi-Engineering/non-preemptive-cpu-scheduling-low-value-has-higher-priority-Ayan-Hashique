// priority.c
// Non-Preemptive Priority CPU Scheduling
// Lower priority value = Higher priority

#include <stdio.h>

int main() {
    int n = 5;

    int process[] = {1,2,3,4,5};
    int burst_time[] = {10,1,2,1,5};
    int priority[] = {3,1,4,5,2};

    int waiting_time[5], turnaround_time[5];

    int i,j,temp;

    // Sorting processes based on priority
    for(i=0;i<n-1;i++) {
        for(j=i+1;j<n;j++) {
            if(priority[i] > priority[j]) {

                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;

                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }

    // Waiting time calculation
    waiting_time[0] = 0;

    for(i=1;i<n;i++) {
        waiting_time[i] = waiting_time[i-1] + burst_time[i-1];
    }

    // Turnaround time calculation
    for(i=0;i<n;i++) {
        turnaround_time[i] = waiting_time[i] + burst_time[i];
    }

    float avg_wt = 0, avg_tat = 0;

    printf("Process\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for(i=0;i<n;i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n",
        process[i], priority[i], burst_time[i], waiting_time[i], turnaround_time[i]);

        avg_wt += waiting_time[i];
        avg_tat += turnaround_time[i];
    }

    printf("\nAverage Waiting Time: %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat/n);

    return 0;
}