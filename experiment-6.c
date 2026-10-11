
#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0;
    int at[10], bt[10], rt[10], pr[10], wt[10], tat[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter arrival time, burst time and priority for P%d: ", i + 1);
        scanf("%d%d%d", &at[i], &bt[i], &pr[i]);
        rt[i] = bt[i];
    }

    while (completed < n) {
        int idx = -1;

        for (i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0 &&
                (idx == -1 || pr[i] < pr[idx]))
                idx = i;
        }

        if (idx == -1) {
            time++;
            continue;
        }

        rt[idx]--;
        time++;

        if (rt[idx] == 0) {
            completed++;
            tat[idx] = time - at[idx];
            wt[idx] = tat[idx] - bt[idx];
        }
    }

    printf("\nProcess\tAT\tBT\tPriority\tWT\tTAT\n");

    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n",
               i + 1, at[i], bt[i], pr[i], wt[i], tat[i]);

    return 0;
}
