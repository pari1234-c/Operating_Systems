#include <stdio.h>

int main() {
    int pages[50], frame[10];
    int n, f, i, j, k;
    int pageFaults = 0;
    int index = 0;
    int found;

    // Input
    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    printf("Enter the reference string:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    // Initialize frames with -1
    for(i = 0; i < f; i++) {
        frame[i] = -1;
    }

    printf("\nPage Frames:\n");

    // FIFO Logic
    for(i = 0; i < n; i++) {
        found = 0;

        // Check if page already exists
        for(j = 0; j < f; j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        // If not found → Page Fault
        if(found == 0) {
            frame[index] = pages[i];
            index = (index + 1) % f;  // Circular FIFO
            pageFaults++;
        }

        // Display frames
        printf("%d\t", pages[i]);
        for(k = 0; k < f; k++) {
            printf("%d ", frame[k]);
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}
