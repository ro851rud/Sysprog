#include <stdio.h>
#include <sys/stat.h>
#include <locale.h>
#include <stdlib.h>

int main (int argc, char* argv[])
{
    struct stat sta;
    int i;
    setlocale(LC_ALL, "");
    if (argc <= 1)
    {
        fprintf(stderr, "no Files enterd\n");
        exit(EXIT_FAILURE);
    }
    for (i = 1; i < argc; ++i)
    {
        if (stat(argv[i], &sta) == -1)
        {
            perror(argv[i]);
        }
        printf("Dateiname: %s Dateigroesse: %lu Bytes\n", argv[i], (unsigned long) sta.st_size);
    }
    return 0;
}