#Musterregel
.c.o:
	gcc -fPIC -g -W -Wall -ansi -pedantic -c -I. $< 

all: libaufgabe6.so

#Makefile
fachnote.o: fachnote.c fachnote.h
	gcc -fPIC -c -I. fachnote.c
liste.o: liste.c fachnote.h liste.h
	gcc -fPIC -c -I. liste.c
    
#Standartzeile 
.PHONY: all clean
clean:
	rm -f libaufgabe6.so liste.o fachnote.o

    
    
#Bibliothekerstellen
libaufgabe6.so: fachnote.o liste.o
	gcc -shared liste.o fachnote.o -o libaufgabe6.so 
