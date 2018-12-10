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

int main(int argc, char *argv[]) /* argv ist eine Matrix (Feld von einem Feld */
{
    char *a;
    int n;
    int j;
    int i;
    int m;
    char* tmp;
    char* s;
    int t;
    srand((unsigned int) time(NULL));
    
    /*---------------------------------------------- Feldgroesse bestimmen*/
    if (argc != 2)
    {
        printf("Aufruf: Stringsort Anzahl");
        return 1;
    }
    
    n = atoi(argv[1]);
    m = strlen(argv[1]) + 1;
    t = m * n;
    a = (char*) malloc(sizeof (char) * t);
    if (a == NULL)
    {
        printf("Kein Speicher Reserviert für a");
        free(a);
        return 1;
    }
    
    /*--------------------------------------------------- Strings wuerfeln*/
    
     
        /*t = a + i * m;*/
        
        printf("Unsortiertes Feld:\n");
        for (i = 0; i < n; ++i)
        {
            int zufall;
            zufall = rand() % n;
            sprintf(a + i * m, "%d", zufall);
            printf("%s\n", (a + i * m));
        }


        /*-------------------------------------------------- Strings sortieren*/
        tmp = (char*) malloc(m);
        for (i = n; i > 1; i--)
        {
            /* groessten Wert nach hinten schieben*/
            
            for (j = 0; j < i - 1; ++j)
            {
                if (strcmp((a + j * m), (a + j * m + m)) > 0)
                {
                    /* Werte tauschen*/
                    memcpy(tmp,a + (j * m + m), m);
                    memcpy(a + (j * m + m), (a + j * m), m);
                    memcpy(a + (j * m), tmp, m);
                }
            }
        }

        /*--------------------------------------------------- Strings ausgeben*/
        printf("Sortiertes Feld:\n");
        s = (char*) malloc(t);
        strcpy(s, a);
        for (i = 1; i < n; ++i)
        {
            if (strcmp((a + i * m), ((a + i * m) - m)) != 0)
            {
                strcat(s, " ");
                strcat(s, (a + i * m));
                
            }
            else 
            {
                strcat(s, "*");
            }
        }
    printf("%s\n", s);
    printf("n = %d\n", n);
    free(a);
    free(s);
    free(tmp);
    return 0;
}
 
