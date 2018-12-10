  
#ifndef FACHNOTE_H
#define FACHNOTE_H
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
void ausgeben(const fach_note *element);
int einlesen(fach_note *element);

#endif