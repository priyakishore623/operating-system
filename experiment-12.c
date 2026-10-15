
#include <stdio.h>

int main()
{
    int i;

    for (i = 0; i < 5; i++)
    {
        printf("Philosopher %d is thinking\n", i + 1);
        printf("Philosopher %d picks up forks\n", i + 1);
        printf("Philosopher %d is eating\n", i + 1);
        printf("Philosopher %d puts down forks\n", i + 1);
    }

    return 0;
}
