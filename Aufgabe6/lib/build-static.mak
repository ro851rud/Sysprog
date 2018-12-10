#Musterregel
.c.o:
	gcc -c $<

all: libaufgabe6.a

#Makefile
fachnote.o: fachnote.c fachnote.h
	gcc -c -I. fachnote.c
liste.o: liste.c fachnote.h liste.h
	gcc -c -I. liste.c
    
#Standartzeile 
.PHONY: all clean
clean:
	rm -f libaufgabe6.a liste.o fachnote.o

    
    
#Bibliothekerstellen
libaufgabe6.a: fachnote.o liste.o
	ar rs libaufgabe6.a fachnote.o liste.o
