#include <stdio.h>
#include <dirent.h>

int main()
{
    DIR *d;
    struct dirent *de;

    d=opendir(".");

    while((de=readdir(d))!=NULL)
        printf("%s\n",de->d_name);

    closedir(d);
    return 0;
}
