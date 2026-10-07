#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int src, dest, n;
    char buffer[100];

    src = open("/tmp/source.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(src, "Hello! This is the source file.\n", 32);
    close(src);

    src = open("/tmp/source.txt", O_RDONLY);
    dest = open("/tmp/destination.txt",
                O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (src < 0 || dest < 0)
    {
        printf("Error opening file\n");
        return 1;
    }

    while ((n = read(src, buffer, sizeof(buffer))) > 0)
        write(dest, buffer, n);

    close(src);
    close(dest);

    printf("File copied successfully.\n");

    return 0;
}
