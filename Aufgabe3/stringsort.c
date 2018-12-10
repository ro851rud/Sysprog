#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h> 
#include <string.h>

/**
 * Stringsort erzeugt zuf&auml;llige Ziffernstrings
 * und sortiert sie alphabetisch
 * @author Robin Rudorf
 * @version 12.04.2018
 */

int main(int argc, char *argv[]) /* argv ist eine Matrix (Feld von einem Feld) */
{
    char **a;
    int n = 0;
    int j;
    int i;
    int m = 0;
    char* tmp;
    char* s;
    srand((unsigned char) time(NULL));
    /*---------------------------------------------- Feldgroesse bestimmen*/
    if (argc != 2)
    {
        printf("Aufruf: Stringsort Anzahl");
        return 1;
    }
    
    n = atoi(argv[1]);
    m = strlen(argv[1]) + 1;
    a = (char**) malloc(n * sizeof(char*));
    
    if (a == NULL)
    {
        printf("Kein Speicher Reserviert für a");
        free(a);
        return 1;
    }
    
    /*--------------------------------------------------- Strings wuerfeln*/
    
     
        
        
        printf("Unsortiertes Feld:\n");
        for (i = 0; i < n; ++i)
        {
            
            a[i] = (char*) calloc(m, sizeof(char));
            if (a[i] == NULL)
            {
                printf("Kein Speicher Reserviert");
                free(a);
                for (j = 0; j < i - 1; i++)
                {
                    free(a[j]);
                }
                return 1;
            }
            sprintf(a[i], "%d", rand() % n);
            printf("%s\n", a[i]);
        }


        /*-------------------------------------------------- Strings sortieren*/
        for (i = n; i > 1; i--)
        {
            /* groessten Wert nach hinten schieben*/
            
            for (j = 0; j < i - 1; ++j)
            {
                if (strcmp(a[j], a[j + 1]) > 0)
                {
                    /* Werte tauschen*/
                    tmp = a[j + 1];
                    a[j + 1] = a[j];
                    a[j] = tmp;
                }
            }
        }

        /*--------------------------------------------------- Strings ausgeben*/
        printf("Sortiertes Feld:\n");
        s = (char*) malloc(n * m);
        strcpy(s, a[0]);
        for (i = 1; i < n; ++i)
        {
            if (strcmp(a[i], a[i - 1]) != 0)
            {
                strcat(s, " ");
                strcat(s, a[i]);
                
            } 
            else 
            {
                strcat(s, "*");
            }
        }
    printf("%s\n", s);
    printf("n = %d\n", n);
    for (i = 0; i < n; ++i)
    {
        free(a[i]);
    }
    free(a);
    free(s);
    return 0;
}

