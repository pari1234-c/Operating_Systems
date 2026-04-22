#include <stdio.h>

int main() {
    int n, i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], wt[n], tat[n];

    // Input Arrival Time and Burst Time
    for(i = 0; i < n; i++) {
        printf("Enter Arrival Time of P%d: ", i+1);
        scanf("%d", &at[i]);

        printf("Enter Burst Time of P%d: ", i+1);
        scanf("%d", &bt[i]);
    }

    // First process
    ct[0] = at[0] + bt[0];

    for(i = 1; i < n; i++) {
        if(ct[i-1] < at[i]) {
            ct[i] = at[i] + bt[i];  // CPU idle case
        } else {
            ct[i] = ct[i-1] + bt[i];
        }
    }

    // Calculate TAT and WT
    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // Display Output
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    float total_wt = 0, total_tat = 0;

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i]);

        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}
