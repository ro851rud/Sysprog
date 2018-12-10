 
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "fachnote.h"
#include "liste.h"
 
 
int einlesen (fach_note *element)
{
    char *Point;

    int scan = scanf("%s", element->Fachname);

    if (scan != 1)
    {
        return 0;
    }
    if (scan == 1)
    {
        if (scanf("%i", &(element->u.note)) == 1)
        {
            Point = strchr(element->Fachname, '_');
            while (Point != NULL)
            {
                *Point = ' ';
                Point = strchr(element->Fachname, '_');
            }
            element->next = NULL;
            element->previous = NULL;
            element->art = benotet;
            return 1;
        }
        else if (scanf("%c", &(element->u.schein)) == 1)
        {
            Point = strchr(element->Fachname, '_');
            while (Point != NULL)
            {
                *Point = ' ';
                Point = strchr(element->Fachname, '_');
            }
            element->next = NULL;
            element->previous = NULL;
            element->art = unbenotet;
            return 1;
        }
    }
    return 0;

}
void ausgeben(const fach_note* element)
{
    double kommazahl;
    printf("%-20s\t", element->Fachname);
    if (element->art == benotet)
    {
        if ((element->u.note >= 10 && element->u.note <=40) ||
            element->u.note == 50)
        {
            kommazahl = ((element->u.note)/10.0);
            printf("%.1f\n", kommazahl);
            
        }
        else
        {
            printf("Fehler: %d\n", element->u.note);
        }
    }
    else
    {
        if (element->u.schein == 'B')
        {
            printf("bestanden\n");
        }
        else if (element->u.schein == 'N')
        {
            printf("nicht bestanden\n");
        }
        else
        {
            printf("Fehler: %c\n", element->u.schein);
        }
    }
}
