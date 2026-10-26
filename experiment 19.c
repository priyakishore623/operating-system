#include <stdio.h>

int shared = 0;
int mutex = 1;

void lock()
{
    while (mutex == 0)
    {
        /* Wait until mutex becomes available */
    }

    mutex = 0;
}

void unlock()
{
    mutex = 1;
}

void process1()
{
    lock();

    printf("\nProcess 1 entered critical section.\n");

    shared++;
    printf("Process 1 updated shared value to: %d\n", shared);

    printf("Process 1 leaving critical section.\n");

    unlock();
}

void process2()
{
    lock();

    printf("\nProcess 2 entered critical section.\n");

    shared++;
    printf("Process 2 updated shared value to: %d\n", shared);

    printf("Process 2 leaving critical section.\n");

    unlock();
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- PROCESS SYNCHRONIZATION USING MUTEX ---\n");
        printf("1. Execute Process 1\n");
        printf("2. Execute Process 2\n");
        printf("3. Display Shared Variable\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                process1();
                break;

            case 2:
                process2();
                break;

            case 3:
                printf("\nShared variable value: %d\n", shared);
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
