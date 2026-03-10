// priority.c
// Non-preemptive Priority Scheduling
// Lower priority value = higher priority

#include <stdio.h>

int main() {
    int n = 5;

    int pid[] = {1,2,3,4,5};
    int bt[] = {10,1,2,1,5};
    int pr[] = {3,1,4,5,2};

    int wt[5], tat[5];

    int i,j;

    // Sort processes by priority
    for(i=0;i<n-1;i++) {
        for(j=i+1;j<n;j++) {
            if(pr[i] > pr[j]) {

                int temp;

                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    // Waiting time
    wt[0] = 0;
    for(i=1;i<n;i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }

    // Turnaround time
    for(i=0;i<n;i++) {
        tat[i] = wt[i] + bt[i];
    }

    float avg_wt = 0, avg_tat = 0;

    printf("Process\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for(i=0;i<n;i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n",
               pid[i], pr[i], bt[i], wt[i], tat[i]);

        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat/n);

    return 0;
}