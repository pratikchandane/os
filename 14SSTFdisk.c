#include <stdio.h>

int main() {
    int req[20], visited[20];
    int n, i, j;
    int head;
    int completed = 0;
    int total_movement = 0;

    printf("Enter number of requests (min 15): ");
    scanf("%d", &n);

    printf("Enter disk request queue:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &req[i]);
        visited[i] = 0;
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nDisk Movement Sequence:\n");
    printf("%d ", head);

    while(completed < n) {

        int min = 9999;
        int index = -1;

        // Find nearest request
        for(i = 0; i < n; i++) {
            if(visited[i] == 0) {

                int diff = req[i] - head;
                if(diff < 0) {
                    diff = -diff;
                }

                if(diff < min) {
                    min = diff;
                    index = i;
                }
            }
        }

        // Move head to nearest request
        visited[index] = 1;
        total_movement = total_movement + min;
        head = req[index];

        printf("-> %d ", head);

        completed++;
    }

    printf("\n\nTotal Head Movement = %d\n", total_movement);

    return 0;
}
