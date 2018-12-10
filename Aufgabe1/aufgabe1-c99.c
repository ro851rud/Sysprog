#include <stdio.h>

int main(void)
{
    int i = 1;
    printf("Adresse: %p, Platzbedarf: %zu, Typ: %s, Name: %s, Wert: %i\n",
           (void*) &i, sizeof i, "int", "i", i);
    short int si = 2;
    printf("Adresse: %p, Platzbedarf: %zu, Typ: %s, Name: %s, Wert: %d\n",
           (void*) &si, sizeof si, "short int", "si", si);
    long int li = 3L;
    printf("Adresse: %p, Platzbedarf: %zu, Typ: %s, Name: %s, Wert: %li\n",
           (void*) &li, sizeof li, "long int", "li", li);
    unsigned int ui = 4U;
    printf("Adresse: %p, Platzbedarf: %zu, Typ: %s, Name: %s, Wert: %u\n",
           (void*) &ui, sizeof ui, "unsigned int", "ui", ui);
    unsigned short int usi = 5U;
    printf("Adresse: %p, Platzbedarf: %zu, Typ: %s, Name: %s, Wert: %u\n",
           (void*) &usi, sizeof usi, "unsigned short int", "usi", usi);
    unsigned long int uli = 6UL;
    printf("Adresse: %p, Platzbedarf: %zu, Typ: %s, Name: %s, Wert: %lu\n",
           (void*) &uli, sizeof uli, "unsigned long int", "uli", uli);

    float f = 1.4F;
    printf("Adresse: %p, Platzbedarf: %zu, Typ: %s, Name: %s, Wert: %f\n",
           (void*) &f, sizeof f, "float", "f", f);
    double d = 2.34;
    printf("Adresse: %p, Platzbedarf: %zu, Typ: %s, Name: %s, Wert: %f\n",
           (void*) &d, sizeof d, "double", "d", d);
    long double ld = 3.45L;
    printf("Adresse: %p, Platzbedarf: %zu, Typ: %s, Name: %s, Wert: %Le\n",
           (void*) &ld, sizeof ld, "long double", "ld", ld);

    char c = 'a';
    printf("Adresse: %p, Platzbedarf: %zu, Typ: %s, Name: %s, Wert: %c\n",
           (void*) &c, sizeof c, "char", "c", c);
    signed char sc = -1;
    printf("Adresse: %p, Platzbedarf: %zu, Typ: %s, Name: %s, Wert: %hhi\n",
           (void*) &sc, sizeof sc, "singned char", "sc", sc);
    unsigned char uc = 0xff;
    printf("Adresse: %p, Platzbedarf: %zu, Typ: %s, Name: %s, Wert: %hhu\n",
           (void*) &uc, sizeof uc, "unsigned char", "uc", uc);

    const char* s = "Hallo";
    printf("Adresse: %p, Platzbedarf: %zu, Typ: %s, Name: %s, Wert: %p\n",
           (void*) &s, sizeof s, "char*", "s", s);

    long long int lli = 70;
    printf("Adresse: %p, Platzbedarf: %zu, Typ: %s, Name: %s, Wert: %lld\n",
           (void*) &lli, sizeof lli, "long long int", "lli", lli);
    unsigned long long int ulli = 40;
    printf("Adresse: %p, Platzbedarf: %zu, Typ: %s, Name: %s, Wert: %llu\n",
           (void*) &ulli, sizeof ulli, "unsigned long long int", "ulli", ulli);


    if (sizeof li == 8 && sizeof s == 8)
    {
        printf("LP64-Datenmodell\n");
    }
    else if (sizeof li == 4 && sizeof s == 4)
    {
        printf("ILP32-Datenmodell\n");
    }
    else
    {
    printf("weder ILP32 noch LP64");
    }
    return 0;
}
