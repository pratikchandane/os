#include <stdio.h>

int main() {
    int n, i;
    int at[20], bt[20], rt[20];
    int ct[20], wt[20], tat[20];
    int time = 0, completed = 0;
    int tq, found;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input arrival and burst times
    for(i = 0; i < n; i++) {
        printf("Enter Arrival Time for P%d: ", i+1);
        scanf("%d", &at[i]);

        printf("Enter Burst Time for P%d: ", i+1);
        scanf("%d", &bt[i]);

        rt[i] = bt[i];  // remaining time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    // Round Robin Logic
    while(completed < n) {
        found = 0;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0) {
                found = 1;

                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    ct[i] = time;
                    rt[i] = 0;
                    completed++;
                }
            }
        }

        // If no process is ready, increment time
        if(found == 0) {
            time++;
        }
    }

    // Calculate TAT and WT
    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // Output
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
