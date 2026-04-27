#include <stdio.h>

int main() {
    int frames[10], pages[30];
    int n, p, i, j, k;
    int count = 0, time = 0;
    int recent[10];

    printf("Enter number of frames: ");
    scanf("%d", &n);

    printf("Enter number of pages: ");
    scanf("%d", &p);

    printf("Enter page reference string:\n");
    for(i = 0; i < p; i++) {
        scanf("%d", &pages[i]);
    }

    // Initialize frames
    for(i = 0; i < n; i++) {
        frames[i] = -1;
        recent[i] = 0;
    }

    printf("\nPage Replacement Process:\n");

    for(i = 0; i < p; i++) {
        int found = 0;

        // Check if page already in frame
        for(j = 0; j < n; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                recent[j] = time++;
                break;
            }
        }

        // If page fault occurs
        if(found == 0) {

            // Find empty frame
            int placed = 0;
            for(j = 0; j < n; j++) {
                if(frames[j] == -1) {
                    frames[j] = pages[i];
                    recent[j] = time++;
                    count++;
                    placed = 1;
                    break;
                }
            }

            // If no empty frame, replace LRU
            if(placed == 0) {
                int min = 0;

                for(j = 1; j < n; j++) {
                    if(recent[j] < recent[min]) {
                        min = j;
                    }
                }

                frames[min] = pages[i];
                recent[min] = time++;
                count++;
            }
        }

        // Display frames
        printf("\nFrames: ");
        for(k = 0; k < n; k++) {
            printf("%d ", frames[k]);
        }
    }

    printf("\n\nTotal Page Faults = %d\n", count);

    return 0;
}
