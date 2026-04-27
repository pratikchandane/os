#include <stdio.h>

int main() {
    int frames[10], pages[30];
    int n, p, i, j;
    int index = 0;   // points to next frame to replace
    int count = 0;   // page faults

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
            frames[index] = pages[i];   // replace oldest page
            index = (index + 1) % n;    // move in circular manner
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
