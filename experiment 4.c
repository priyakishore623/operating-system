#include <stdio.h>

int main()
{
    int n, i, j;
    int pid[20], bt[20], wt[20], tat[20];
    int temp;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input process details
    for(i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        printf("Enter execution time for P%d: ", pid[i]);
        scanf("%d", &bt[i]);
    }

    // Sort processes according to execution time
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(bt[i] > bt[j])
            {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    // Calculate waiting time
    wt[0] = 0;

    for(i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Calculate turnaround time
    for(i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
    }

    // Display result
    printf("\nProcess\tExecution Time\tWaiting Time\tTurnaround Time\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\n",
               pid[i], bt[i], wt[i], tat[i]);
    }

    return 0;
}
