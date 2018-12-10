#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "liste.h"
#include "fachnote.h"

void* einfuegen(fach_note *kopf, fach_note *neu, fach_note **entfernt)
{
    fach_note *Point;
    if (kopf == NULL)
    {
        kopf = neu;
        *entfernt = NULL;
        return kopf;
    }
    else
    {
        neu->next = kopf;
        kopf->previous = neu;
        kopf = neu;
        neu = NULL;
        *entfernt = NULL;


        Point = kopf->next;

        while (Point != NULL)
        {
            if (strcmp(kopf->Fachname, Point->Fachname) == 0 && kopf->art == Point->art)
            {
                if(Point->next == NULL)
                {
                    *entfernt = Point;
                    Point->previous->next = NULL;

                }
                else
                {
                    *entfernt = Point;
                    Point->previous->next = Point->next;
                    Point->next->previous = Point->previous;
                }
                break;
            }
            else
            {
                Point = Point->next;
            }
        }
        return kopf;
    }
}
void schleife(fach_note *kopf, Funktionspointer fp)
{
    while (kopf != NULL)
    {
        fp(kopf);
        kopf = kopf->next;
    }
}
fach_note* entfernen(fach_note *kopf, fach_note **entfernt)
{
    *entfernt = kopf;
    if (kopf == NULL)
    {
        return NULL;
    }
    kopf = kopf->next;
    if (kopf != NULL)
    {
        kopf->previous->next = NULL;
        kopf->previous = NULL;
    }
    return kopf;
} 
