#include <stdio.h>

int main() {
    int n, i;
    int at[20], bt[20], ct[20], wt[20], tat[20];
    int time = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input arrival and burst times
    for(i = 0; i < n; i++) {
        printf("Enter Arrival Time for P%d: ", i+1);
        scanf("%d", &at[i]);

        printf("Enter Burst Time for P%d: ", i+1);
        scanf("%d", &bt[i]);
    }

    // FCFS Scheduling Logic
    for(i = 0; i < n; i++) {

        // If CPU is idle
        if(time < at[i]) {
            time = at[i];
        }

        // Completion time
        ct[i] = time + bt[i];
        time = ct[i];
    }

    // Calculate TAT and WT
    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // Output
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
