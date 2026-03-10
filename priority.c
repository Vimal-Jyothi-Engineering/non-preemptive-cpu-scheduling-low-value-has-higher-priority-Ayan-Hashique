#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int pid;
    int arrival;
    int burst;
    int priority;
    int waiting;
    int turnaround;
    int finish;
    bool completed;
} Process;

int main() {
    int n;
    // Reading number of processes - usually no prompt is needed for autograders
    if (scanf("%d", &n) != 1) return 0;

    Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        scanf("%d %d %d", &p[i].arrival, &p[i].burst, &p[i].priority);
        p[i].completed = false;
    }

    int completed_count = 0, current_time = 0;
    float total_wt = 0, total_tat = 0;

    while (completed_count < n) {
        int idx = -1;
        int min_priority = 1e9;

        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= current_time && !p[i].completed) {
                // Check for lower priority value (higher priority)
                if (p[i].priority < min_priority) {
                    min_priority = p[i].priority;
                    idx = i;
                }
                // Tie-breaker: If priorities are same, choose earlier arrival
                else if (p[i].priority == min_priority) {
                    if (p[i].arrival < p[idx].arrival) {
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1) {
            p[idx].waiting = current_time - p[idx].arrival;
            if (p[idx].waiting < 0) p[idx].waiting = 0; // Guard against negative WT

            current_time += p[idx].burst;
            p[idx].finish = current_time;
            p[idx].turnaround = p[idx].finish - p[idx].arrival;
            
            total_wt += p[idx].waiting;
            total_tat += p[idx].turnaround;
            p[idx].completed = true;
            completed_count++;
        } else {
            // If no process has arrived, jump to the next arrival time
            current_time++;
        }
    }

    // Standard GitHub Classroom Output Table Format
    printf("PID\tAT\tBT\tPriority\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\n", 
               p[i].pid, p[i].arrival, p[i].burst, p[i].priority, 
               p[i].waiting, p[i].turnaround);
    }

    printf("\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}