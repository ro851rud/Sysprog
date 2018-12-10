 
#ifndef LISTE_H
#define LISTE_H
#include "fachnote.h"
 typedef void (*Funktionspointer)(const fach_note *);   

 
void schleife(fach_note *, Funktionspointer fp);
fach_note* entfernen(fach_note *, fach_note**);
void* einfuegen(fach_note *kopf, fach_note *neu, fach_note **entfernt);

#endif