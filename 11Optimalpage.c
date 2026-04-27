#include <stdio.h>

int main() {
    int frames[10], pages[30];
    int n, p, i, j, k;
    int count = 0;

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
    }

    printf("\nPage Replacement Process:\n");

    for(i = 0; i < p; i++) {
        int found = 0;

        // Check if page already exists (HIT)
        for(j = 0; j < n; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        // If page fault occurs
        if(found == 0) {

            int pos = -1;

            // Check for empty frame
            for(j = 0; j < n; j++) {
                if(frames[j] == -1) {
                    pos = j;
                    break;
                }
            }

            // If no empty frame, apply Optimal logic
            if(pos == -1) {
                int farthest = i + 1;
                int index = -1;

                for(j = 0; j < n; j++) {
                    int foundFuture = 0;

                    for(k = i + 1; k < p; k++) {
                        if(frames[j] == pages[k]) {
                            if(k > farthest) {
                                farthest = k;
                                index = j;
                            }
                            foundFuture = 1;
                            break;
                        }
                    }

                    // If page not used again → replace immediately
                    if(foundFuture == 0) {
                        index = j;
                        break;
                    }
                }

                pos = index;
            }

            // Replace page
            frames[pos] = pages[i];
            count++;
        }

        // Display frames
        printf("\nFrames: ");
        for(j = 0; j < n; j++) {
            printf("%d ", frames[j]);
        }
    }

    printf("\n\nTotal Page Faults = %d\n", count);

    return 0;
}
