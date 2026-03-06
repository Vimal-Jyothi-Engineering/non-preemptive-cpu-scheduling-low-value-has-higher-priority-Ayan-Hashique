#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char pid[10];
    int at;   // Arrival Time
    int bt;   // Burst Time
    int pr;   // Priority
    int wt;   // Waiting Time
    int tat;  // Turnaround Time
    int ct;   // Completion Time
    int done; // 0 = not finished, 1 = finished
} Process;

int main() {
    int n;
    Process p[MAX];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d", p[i].pid, &p[i].at, &p[i].bt, &p[i].pr);
        p[i].done = 0;
    }

   ..
     ..
     ..
     ..
     ..
     ..
     ...
     ...
    printf("Waiting Time:\n");
    for (int i = 0; i < n; i++)
        printf("%s %d\n", p[i].pid, p[i].wt);

    printf("Turnaround Time:\n");
    for (int i = 0; i < n; i++)
        printf("%s %d\n", p[i].pid, p[i].tat);

    printf("Average Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}
