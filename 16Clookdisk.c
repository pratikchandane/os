#include <stdio.h>

int main() {
    int req[20], left[20], right[20];
    int n, i, j;
    int head;
    int leftCount = 0, rightCount = 0;
    int total_movement = 0;

    printf("Enter number of requests (min 15): ");
    scanf("%d", &n);

    printf("Enter disk request queue:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    // Divide requests into left and right of head
    for(i = 0; i < n; i++) {
        if(req[i] < head) {
            left[leftCount++] = req[i];
        }
        else {
            right[rightCount++] = req[i];
        }
    }

    // Sort left array
    for(i = 0; i < leftCount - 1; i++) {
        for(j = i + 1; j < leftCount; j++) {
            if(left[i] > left[j]) {
                int temp = left[i];
                left[i] = left[j];
                left[j] = temp;
            }
        }
    }

    // Sort right array
    for(i = 0; i < rightCount - 1; i++) {
        for(j = i + 1; j < rightCount; j++) {
            if(right[i] > right[j]) {
                int temp = right[i];
                right[i] = right[j];
                right[j] = temp;
            }
        }
    }

    printf("\nDisk Movement Sequence:\n");
    printf("%d ", head);

    // Move right side first (as per C-LOOK)
    for(i = 0; i < rightCount; i++) {
        total_movement += (right[i] - head);
        head = right[i];
        printf("-> %d ", head);
    }

    // Jump to smallest request in left (no travel to 0)
    if(leftCount > 0) {
        total_movement += (head - left[0]);
        head = left[0];
        printf("-> %d ", head);

        for(i = 1; i < leftCount; i++) {
            total_movement += (left[i] - head);
            head = left[i];
            printf("-> %d ", head);
        }
    }

    printf("\n\nTotal Head Movement = %d\n", total_movement);

    return 0;
}
