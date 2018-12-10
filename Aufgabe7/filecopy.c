#include <stdio.h>
#include <sys/stat.h> /*mode_t, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH*/
#include <locale.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>    /*open, O_RDONLY, O_WRONLY, O_CREAT, O_EXCL */
#include <unistd.h>   /*read, write*/
#include <dirent.h>

int main (int argc, char* argv[])
{
    const mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH; /*Zugriffsrechte*/
    int in, out, error;
    struct stat info;
    void *puffer;
    int size;
    
    if (setlocale(LC_MESSAGES, "de_DE.UTF-8") == NULL)
    {
        fprintf(stderr,"Kein deutscher Text\n");
    }
    
    if (argc != 3)
    {
        fprintf(stderr, "zu wenige/viele Argumente eingegeben\n");
        return -1;
    }
    in = open(argv[1], O_RDONLY);
    if (in == -1)   /* fehlerbehandlung */
    {
        fprintf(stderr, "oefnen nicht moeglich Datei1\n");
        return -1;
    }
    out = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, mode);
    if (out == -1)  /* fehlerbehandlung */
    {
        fprintf(stderr, "oefnen nicht moeglich Datei2\n");
        return -1;
    }
    if(fstat(in, &info) != 0)
    {
        fprintf(stderr, argv[1]);
        return -1;
    }
    size = info.st_size;
    puffer = malloc(size);
    error = read(in, puffer, size);
    if (error == -1)
    {
        fprintf(stderr, "lesen nicht moeglich\n");
        return -1;
    }
    else if (error != size)
    {
        fprintf(stderr, "falsche Dateigroesse\n");
        return -1;
    }
    error = write(out, puffer, size);
    if (error == -1)
    {
        fprintf(stderr, "schreiben nicht moeglich\n");
        return -1;
    }
    else if (error != size)
    {
        fprintf(stderr, "falsche Dateigroesse2\n");
        return -1;
    }
    free(puffer);
    close(in);
    close(out);
    return 0;
}




