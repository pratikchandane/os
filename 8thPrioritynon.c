#include <stdio.h>

int main() {
    int n, i, j;
    int at[20], bt[20], pr[20];
    int ct[20], wt[20], tat[20];
    int completed[20];
    int time = 0, done = 0;
    int min, idx;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input process details
    for(i = 0; i < n; i++) {
        printf("Enter Arrival Time for P%d: ", i+1);
        scanf("%d", &at[i]);

        printf("Enter Burst Time for P%d: ", i+1);
        scanf("%d", &bt[i]);

        printf("Enter Priority for P%d (lower number = higher priority): ", i+1);
        scanf("%d", &pr[i]);

        completed[i] = 0;
    }

    // Main scheduling loop
    while(done < n) {

        min = 9999;
        idx = -1;

        // Select highest priority process among arrived ones
        for(i = 0; i < n; i++) {
            if(at[i] <= time && completed[i] == 0) {
                if(pr[i] < min) {
                    min = pr[i];
                    idx = i;
                }
            }
        }

        if(idx != -1) {
            time = time + bt[idx];   // non-preemptive execution
            ct[idx] = time;
            completed[idx] = 1;
            done++;
        }
        else {
            time++; // CPU idle
        }
    }

    // Calculate TAT and WT
    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // Output
    printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
