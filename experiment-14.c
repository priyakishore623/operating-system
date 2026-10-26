#include <stdio.h>
#include <string.h>

#define MAX 20

int main()
{
    char files[MAX][30];
    int count = 0;
    int choice, i, j;
    char filename[30];

    while (1)
    {
        printf("\n--- SINGLE LEVEL DIRECTORY ---\n");
        printf("1. Create File\n");
        printf("2. Delete File\n");
        printf("3. Search File\n");
        printf("4. Display Files\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (count == MAX)
                {
                    printf("Directory is full!\n");
                    break;
                }

                printf("Enter file name: ");
                scanf("%s", filename);

                for (i = 0; i < count; i++)
                {
                    if (strcmp(files[i], filename) == 0)
                    {
                        printf("File already exists!\n");
                        break;
                    }
                }

                if (i == count)
                {
                    strcpy(files[count], filename);
                    count++;
                    printf("File created successfully.\n");
                }
                break;

            case 2:
                printf("Enter file name to delete: ");
                scanf("%s", filename);

                for (i = 0; i < count; i++)
                {
                    if (strcmp(files[i], filename) == 0)
                    {
                        for (j = i; j < count - 1; j++)
                        {
                            strcpy(files[j], files[j + 1]);
                        }

                        count--;
                        printf("File deleted successfully.\n");
                        break;
                    }
                }

                if (i == count)
                {
                    printf("File not found!\n");
                }
                break;

            case 3:
                printf("Enter file name to search: ");
                scanf("%s", filename);

                for (i = 0; i < count; i++)
                {
                    if (strcmp(files[i], filename) == 0)
                    {
                        printf("File found.\n");
                        break;
                    }
                }

                if (i == count)
                {
                    printf("File not found.\n");
                }
                break;

            case 4:
                if (count == 0)
                {
                    printf("Directory is empty.\n");
                }
                else
                {
                    printf("\nFiles in the directory:\n");

                    for (i = 0; i < count; i++)
                    {
                        printf("%d. %s\n", i + 1, files[i]);
                    }
                }
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
