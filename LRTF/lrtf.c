#include <stdio.h>

int main() {
    int n, i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[20], bt[20], rt[20];
    int ct[20], tat[20], wt[20], response[20];
    int started[20];

    int completed = 0, time = 0;

    // Input
    for(i = 0; i < n; i++) {
        printf("\nProcess P%d\n", i + 1);

        printf("Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Burst Time: ");
        scanf("%d", &bt[i]);

        rt[i] = bt[i];
        started[i] = 0;
    }

    // LRTF Logic
    while(completed < n) {
        int max_rt = -1;
        int index = -1;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0) {
                if(rt[i] > max_rt) {
                    max_rt = rt[i];
                    index = i;
                }
            }
        }

        if(index != -1) {
            // First response time
            if(started[index] == 0) {
                response[index] = time - at[index];
                started[index] = 1;
            }

            rt[index]--;
            time++;

            // If process completed
            if(rt[index] == 0) {
                completed++;
                ct[index] = time;
                tat[index] = ct[index] - at[index];
                wt[index] = tat[index] - bt[index];
            }
        } else {
            time++; // idle CPU
        }
    }

    float avg_wt = 0, avg_tat = 0, avg_rt = 0;

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i], response[i]);

        avg_wt += wt[i];
        avg_tat += tat[i];
        avg_rt += response[i];
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f", avg_tat/n);
    printf("\nAverage Response Time = %.2f\n", avg_rt/n);

    return 0;
}
