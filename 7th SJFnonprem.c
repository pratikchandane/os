#include <stdio.h>

int main() {
    int n, i, j;
    int at[20], bt[20], ct[20], wt[20], tat[20];
    int completed[20];
    int time = 0, min, idx;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input arrival and burst time
    for(i = 0; i < n; i++) {
        printf("Enter Arrival Time for P%d: ", i+1);
        scanf("%d", &at[i]);

        printf("Enter Burst Time for P%d: ", i+1);
        scanf("%d", &bt[i]);

        completed[i] = 0;
    }

    int done = 0;

    // Main SJF logic
    while(done < n) {

        min = 9999;
        idx = -1;

        // Find shortest job among arrived processes
        for(i = 0; i < n; i++) {
            if(at[i] <= time && completed[i] == 0) {
                if(bt[i] < min) {
                    min = bt[i];
                    idx = i;
                }
            }
        }

        if(idx != -1) {
            time = time + bt[idx];
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
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
