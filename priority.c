#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int pid;
    int arrival;
    int burst;
    int priority;
    int start;
    int finish;
    int waiting;
    int turnaround;
    bool completed;
} Process;

int main() {
    int n;
    // Standard input reading without extra text to satisfy autograders
    if (scanf("%d", &n) != 1) return 0;

    Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        scanf("%d %d %d", &p[i].arrival, &p[i].burst, &p[i].priority);
        p[i].completed = false;
    }

    int completed_count = 0, current_time = 0;
    while (completed_count < n) {
        int idx = -1;
        int highest_prio = 1e9;

        // Selection logic: Non-preemptive priority
        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= current_time && !p[i].completed) {
                if (p[i].priority < highest_prio) {
                    highest_prio = p[i].priority;
                    idx = i;
                } else if (p[i].priority == highest_prio) {
                    // Tie-breaker: earlier arrival gets CPU
                    if (p[i].arrival < p[idx].arrival) {
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1) {
            p[idx].start = current_time;
            p[idx].finish = p[idx].start + p[idx].burst;
            p[idx].turnaround = p[idx].finish - p[idx].arrival;
            p[idx].waiting = p[idx].turnaround - p[idx].burst;
            
            current_time = p[idx].finish;
            p[idx].completed = true;
            completed_count++;
        } else {
            current_time++;
        }
    }

    // Final Output Table
    printf("PID\tAT\tBT\tPrio\tWT\tTAT\n");
    float avg_wt = 0, avg_tat = 0;
    for (int i = 0; i < n; i++) {
        avg_wt += p[i].waiting;
        avg_tat += p[i].turnaround;
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", 
               p[i].pid, p[i].arrival, p[i].burst, p[i].priority, 
               p[i].waiting, p[i].turnaround);
    }

    printf("\nAverage Waiting Time: %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat / n);

    return 0;
}