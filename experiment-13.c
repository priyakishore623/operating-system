#include <stdio.h>

void firstFit(int block[], int m, int process[], int n)
{
    int allocation[n];

    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (block[j] >= process[i])
            {
                allocation[i] = j;
                block[j] -= process[i];
                break;
            }
        }
    }

    printf("\nFIRST FIT\n");
    printf("Process\tSize\tBlock\n");

    for (int i = 0; i < n; i++)
    {
        if (allocation[i] != -1)
            printf("P%d\t%d\tB%d\n", i + 1, process[i], allocation[i] + 1);
        else
            printf("P%d\t%d\tNot Allocated\n", i + 1, process[i]);
    }
}

void bestFit(int block[], int m, int process[], int n)
{
    int allocation[n];

    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++)
    {
        int best = -1;

        for (int j = 0; j < m; j++)
        {
            if (block[j] >= process[i])
            {
                if (best == -1 || block[j] < block[best])
                    best = j;
            }
        }

        if (best != -1)
        {
            allocation[i] = best;
            block[best] -= process[i];
        }
    }

    printf("\nBEST FIT\n");
    printf("Process\tSize\tBlock\n");

    for (int i = 0; i < n; i++)
    {
        if (allocation[i] != -1)
            printf("P%d\t%d\tB%d\n", i + 1, process[i], allocation[i] + 1);
        else
            printf("P%d\t%d\tNot Allocated\n", i + 1, process[i]);
    }
}

void worstFit(int block[], int m, int process[], int n)
{
    int allocation[n];

    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++)
    {
        int worst = -1;

        for (int j = 0; j < m; j++)
        {
            if (block[j] >= process[i])
            {
                if (worst == -1 || block[j] > block[worst])
                    worst = j;
            }
        }

        if (worst != -1)
        {
            allocation[i] = worst;
            block[worst] -= process[i];
        }
    }

    printf("\nWORST FIT\n");
    printf("Process\tSize\tBlock\n");

    for (int i = 0; i < n; i++)
    {
        if (allocation[i] != -1)
            printf("P%d\t%d\tB%d\n", i + 1, process[i], allocation[i] + 1);
        else
            printf("P%d\t%d\tNot Allocated\n", i + 1, process[i]);
    }
}

int main()
{
    int m, n;

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    int block[m];
    int original[m];

    printf("Enter size of each memory block:\n");
    for (int i = 0; i < m; i++)
    {
        printf("Block %d: ", i + 1);
        scanf("%d", &block[i]);
        original[i] = block[i];
    }

    printf("\nEnter number of processes: ");
    scanf("%d", &n);

    int process[n];

    printf("Enter size of each process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &process[i]);
    }

    // First Fit
    firstFit(block, m, process, n);

    // Restore original block sizes
    for (int i = 0; i < m; i++)
        block[i] = original[i];

    // Best Fit
    bestFit(block, m, process, n);

    // Restore original block sizes
    for (int i = 0; i < m; i++)
        block[i] = original[i];

    // Worst Fit
    worstFit(block, m, process, n);

    return 0;
}
