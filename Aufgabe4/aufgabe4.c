/*
 * aufgabe4.c
 *
 * Liest Fachnamen mit Beurteilung ein und gibt dann einen Notenspiegel aus.
 *
 * Autor: Robin
 * Erstellt am: 03.05.2018
 */

/* #include-Anweisungen, symbolische Konstante, Typen ... */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#define FELDGR 20   /*Definiert Feldgroese fur den Fachname*/



enum vergleich            /*sagt an ob Pruefung oder Schein*/
{
    benotet,
    unbenotet
};
struct fach_note                    /*aus struct werden alle erreichbaren Elemente geholt*/
{
    struct fach_note *next;                /*next zeigt auf das naechste Element*/
    struct fach_note *previous;
    char Fachname[FELDGR];        /*previous zeigt auf das vorherige Element*/
    enum vergleich art;
    union                           /*aus unionm kann nur ein Objekt genommen werden*/
    {
        int note;
        char schein;
    } u;
};
typedef struct fach_note fach_note; /*definiert den Typ von fach_note*/

typedef void (*Funktionspointer)(const fach_note *);   /*typdef fuer eine
                                                        Funlktion mit dem Namen Funktionspointer und den
                                                        Eingabeparameter fuer konstante fach_note*/

void ausgeben(const fach_note *element);
int einlesen(fach_note *element);
void schleife(fach_note *, Funktionspointer fp);
fach_note* entfernen(fach_note *, fach_note**);
void* einfuegen(fach_note *kopf, fach_note *neu, fach_note **entfernt);


int main(void)
{
    fach_note *notenspiegel = NULL;
    fach_note *p;
    fach_note *q;

    /*------------------------------------------- Notenspiegel einlesen */
    fprintf(stderr, "Faecher mit Noten eingeben (Ende mit Strg-D):\n");
// 
    for (;;)
    {
        p = (fach_note *) malloc(sizeof (fach_note));
        if (p == NULL)
        {
            fprintf(stderr, "Zu viele Faecher!\n");
            break;
        }

        if (! einlesen(p))
        {
            fprintf(stderr, "Eingabeende!\n");
            free(p);
            break;
        }

        notenspiegel = einfuegen(notenspiegel, p, &q);
        if (q != NULL)
        {
            fprintf(stderr, "Alte Eingabe ueberschrieben!\n");
            free(q);
        }
    }

    /*------------------------------------------- Notenspiegel ausgeben */
    printf("Notenspiegel:\n");

    schleife(notenspiegel, ausgeben);

    /*------------------------------------------- Notenspiegel loeschen */
    while (notenspiegel != NULL)
    {
        notenspiegel = entfernen(notenspiegel, &p);
        free(p);
    }

    return 0;
}

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