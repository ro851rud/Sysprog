#Mikefile

#Komando-Variablen
CC = gcc
CPPFLAGS = -I../lib
LDFLAGS = -L../lib
CFLAGS = -c -g -W -Wall -pedantic -ansi -fPIC
RM = rm -f
AR = ar rs

#Hilfsvariablen
TARGET = notenspiegel
OBJECTS = fachnote.h liste.h
SOURCES = $(OBJECTS:.o=.c)
HEADERS = ../lib/$(OBJECTS)
LIB = aufgabe6

#Musterregel
%.o:%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $<
	
#Standardzeile
.PHONY: all clean

all: $(TARGET)

clean:
	$(RM) $(TARGET) $(TARGET).o depend

depend: $(SOURCES) $(HEADERS)
	$(CC) -MM $(SOURCES) > $@

#Programmerstellung
$(TARGET): $(TARGET).o
	$(CC) -o $(TARGET) $(TARGET).o $(LDFLAGS) -l $(LIB)


#Abhängigkeiten
include depend 
