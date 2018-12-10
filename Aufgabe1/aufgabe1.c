#include <stdio.h>

int main(void)
{
    int i = 1;
    short int si = 2;
    long int li = 3L;
    unsigned int ui = 4U;
    unsigned short int usi = 5U;
    unsigned long int uli = 6UL;

    float f = 1.4F;
    double d = 2.34;
    long double ld = 3.45L;

    char c = 'a';
    signed char sc = -1;
    unsigned char uc = 0xff;

    const char* s = "Hallo";

    printf("Adresse: %p, Platzbedarf: %lu, Typ: %s, Name: %s, Wert: %i\n",
           (void*) &i, (unsigned long) sizeof i, "int", "i", i);
    printf("Adresse: %p, Platzbedarf: %lu, Typ: %s, Name: %s, Wert: %d\n",
           (void*) &si, (unsigned long) sizeof si, "short int", "si", si);
    printf("Adresse: %p, Platzbedarf: %lu, Typ: %s, Name: %s, Wert: %li\n",
           (void*) &li, (unsigned long) sizeof li, "long int", "li", li);
    printf("Adresse: %p, Platzbedarf: %lu, Typ: %s, Name: %s, Wert: %u\n",
           (void*) &ui, (unsigned long) sizeof ui, "unsigned int", "ui", ui);
    printf("Adresse: %p, Platzbedarf: %lu, Typ: %s, Name: %s, Wert: %u\n",
           (void*) &usi, (unsigned long) sizeof usi, "unsigned short int", "usi", usi);
    printf("Adresse: %p, Platzbedarf: %lu, Typ: %s, Name: %s, Wert: %lu\n",
           (void*) &uli, (unsigned long) sizeof uli, "unsigned long int", "uli", uli);
    printf("Adresse: %p, Platzbedarf: %lu, Typ: %s, Name: %s, Wert: %f\n",
           (void*) &f, (unsigned long) sizeof f, "float", "f", f);
    printf("Adresse: %p, Platzbedarf: %lu, Typ: %s, Name: %s, Wert: %f\n",
           (void*) &d, (unsigned long) sizeof d, "double", "d", d);
    printf("Adresse: %p, Platzbedarf: %lu, Typ: %s, Name: %s, Wert: %Le\n",
           (void*) &ld, (unsigned long) sizeof ld, "long double", "ld", ld);
    printf("Adresse: %p, Platzbedarf: %lu, Typ: %s, Name: %s, Wert: %c\n",
           (void*) &c, (unsigned long) sizeof c, "char", "c", c);
    printf("Adresse: %p, Platzbedarf: %lu, Typ: %s, Name: %s, Wert: %d\n",
           (void*) &sc, (unsigned long) sizeof sc, "singned char", "sc", sc);
    printf("Adresse: %p, Platzbedarf: %lu, Typ: %s, Name: %s, Wert: %d\n",
           (void*) &uc, (unsigned long) sizeof uc, "unsigned char", "uc", uc);
    printf("Adresse: %p, Platzbedarf: %lu, Typ: %s, Name: %s, Wert: %p\n",
           (void*) &s, (unsigned long) sizeof s, "char*", "s", s);
    if (sizeof li == 8 && sizeof s == 8 && sizeof i == 4)
    {
        printf("LP64-Datenmodell\n");
    } else if (sizeof li == 4 && sizeof s == 4 && sizeof i == 4)
    {
        printf("ILP32-Datenmodell\n");
    }
    else
    {
    printf("weder ILP32 noch LP64");
    }
    return 0;
}