#include <stdio.h>

int main() {
    int req[20];
    int n, i;
    int head;
    int total_movement = 0;

    printf("Enter number of requests (min 15): ");
    scanf("%d", &n);

    printf("Enter disk request queue:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nDisk Movement Sequence:\n");
    printf("%d ", head);

    // FCFS logic
    for(i = 0; i < n; i++) {

        int movement = req[i] - head;

        if(movement < 0) {
            movement = -movement;
        }

        total_movement = total_movement + movement;

        head = req[i];

        printf("-> %d ", head);
    }

    printf("\n\nTotal Head Movement = %d\n", total_movement);

    return 0;
}
