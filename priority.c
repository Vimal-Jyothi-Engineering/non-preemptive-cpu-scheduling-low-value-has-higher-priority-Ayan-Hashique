#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int pid;        // Process ID
    int arrival;    // Arrival Time
    int burst;      // Burst Time
    int priority;   // Priority (Lower = Higher priority)
    int start;      // Start Time
    int finish;     // Completion Time
    int waiting;    // Waiting Time
    int turnaround; // Turnaround Time
    bool completed; // Completion status
} Process;

void calculateMetrics(Process p[], int n) {
    int completed_count = 0, current_time = 0;
    
    while (completed_count < n) {
        int idx = -1;
        int highest_priority = 1e9; // Infinity equivalent

        // Find process with highest priority that has arrived and isn't finished
        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= current_time && !p[i].completed) {
                if (p[i].priority < highest_priority) {
                    highest_priority = p[i].priority;
                    idx = i;
                }
                // Tie-breaker: If priorities are equal, use Arrival Time (FCFS)
                else if (p[i].priority == highest_priority) {
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
            // No process has arrived yet, jump time forward
            current_time++;
        }
    }
}

void displayResults(Process p[], int n) {
    float total_wt = 0, total_tat = 0;
    printf("\nPID\tArrival\tBurst\tPriority\tFinish\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        total_wt += p[i].waiting;
        total_tat += p[i].turnaround;
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n", 
               p[i].pid, p[i].arrival, p[i].burst, p[i].priority, 
               p[i].finish, p[i].waiting, p[i].turnaround);
    }
    printf("\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Process %d [Arrival Burst Priority]: ", i + 1);
        scanf("%d %d %d", &p[i].arrival, &p[i].burst, &p[i].priority);
        p[i].completed = false;
    }

    calculateMetrics(p, n);
    displayResults(p, n);

    return 0;
}