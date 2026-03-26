#include <stdio.h>

int main() {
    int n, i, j;
    
    // Number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int alloc[n], max[n], need[n];
    int available;

    // Input Allocation
    printf("Enter Allocation for each process:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &alloc[i]);
    }

    // Input Maximum
    printf("Enter Maximum requirement for each process:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &max[i]);
    }

    // Input Available resources
    printf("Enter Available resources: ");
    scanf("%d", &available);

    // Calculate Need = Max - Allocation
    for(i = 0; i < n; i++) {
        need[i] = max[i] - alloc[i];
    }

    int finish[n];
    for(i = 0; i < n; i++) {
        finish[i] = 0;
    }

    int safeSeq[n];
    int count = 0;

    // Safety Algorithm
    while(count < n) {
        int found = 0;

        for(i = 0; i < n; i++) {
            if(finish[i] == 0 && need[i] <= available) {
                available += alloc[i];   // Release resources
                safeSeq[count++] = i;
                finish[i] = 1;
                found = 1;
            }
        }

        if(found == 0) {
            printf("System is NOT in safe state\n");
            return 0;
        }
    }

    // Safe sequence
    printf("System is in SAFE state\nSafe sequence: ");
    for(i = 0; i < n; i++) {
        printf("P%d ", safeSeq[i]);
    }

    return 0;
}
