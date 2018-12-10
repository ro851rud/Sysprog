#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

/**
 * Bubblesort liest ganze Zahlen ein und sortiert sie aufsteigend.
 * @author Robin Rudorf
 * @version 05.04.2018
 */
int main(int argc, char *argv[]) /* argv ist eine Matrix (Feld von einem Feld */
{

    /**
     * main ist der Startpunkt des Programms.
     * @param args wird nicht verwendet.
     */
    
    int i, j;
    int zahl = 0;
    int n;
    int *a;
    srand((unsigned int) time(NULL));

    /*----------------------------------------------- Feldgroesse einlesen */
    if (argc != 2)
    {
        printf("Aufruf: Bubblesort Anzahl\n");
        return 1;
    }
    
    n = atoi(argv[1]);
    a = (int*) calloc(n, sizeof (int));
    
    /*---------------------------------------------------- Zahlen einlesen */
    
    printf("Bitte %d ganze Zahlen eingeben: \n", n);
    
    
    

    for (i = 0; i < n; ++i)
    {
        if (zahl == EOF || (zahl = scanf("%d\n", &a[i])) < 1)
        {
            a[i] = rand();
            printf("%d\n", a[i]);
        }
    }

    /*--------------------------------------------------- Zahlen sortieren */

    for (i = n; i > 1; i--)
    {
        /* groessten Wert nach hinten schieben */
        for (j = 0; j < i - 1; ++j)
        {
            if (a[j] > a[j + 1])
            {
                int tmp;
                /* Werte tauschen */
                tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
        }
    }

    /*---------------------------------------------------- Zahlen ausgeben */
    printf("Sortierte Zahlenfolge: \n");

    for (i = 0; i < n; ++i)
    {
        printf("%d\n", a[i]);
    }
    
    free(s);
    
    return 0;
}

