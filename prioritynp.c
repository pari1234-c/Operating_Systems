#include <stdio.h>

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], pr[n], ct[n], tat[n], wt[n], completed[n];

    for(int i = 0; i < n; i++) {
        printf("Enter AT, BT, Priority of P%d: ", i+1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        completed[i] = 0;
    }

    int time = 0, done = 0;

    while(done < n) {
        int idx = -1;
        int highest = 9999;

        for(int i = 0; i < n; i++) {
            if(at[i] <= time && completed[i] == 0) {
                if(pr[i] < highest) {
                    highest = pr[i];
                    idx = i;
                }
            }
        }

        if(idx != -1) {
            time += bt[idx];
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];

            completed[idx] = 1;
            done++;
        } else {
            time++;
        }
    }

    float total_wt = 0, total_tat = 0;

    printf("\nProcess\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);

        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage WT = %.2f", total_wt/n);
    printf("\nAverage TAT = %.2f\n", total_tat/n);

    return 0;
}
