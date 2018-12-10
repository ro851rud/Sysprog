#Mikefile

#Komando-Variablen
CC = gcc
CPPFLAGS = -I.
CFLAGS = -c -g -W -Wall -pedantic -ansi -fPIC
LIBTYPE = a
RM = rm -f
AR = ar rs

#Hilfsvariablen
TARGET = libaufgabe6
OBJECTS = fachnote.o liste.o
SOURCES = $(OBJECTS:.o=.c)
HEADERS = $(OBJECTS:.o=.h)

#Musterregel
#$(OBJECTS): $(SOURCES)
#	$(CC) $(CPPFLAGS) $(CFLAGS) $<

#Standardzeile
.PHONY: all clean

all: $(TARGET).$(LIBTYPE)

clean:
	$(RM) $(TARGET).a $(TARGET).so $(OBJECTS) depend

depend: $(SOURCES) $(HEADERS)
	$(CC) -MM $(SOURCES) > $@

#Programmerstellung
$(TARGET).a: $(OBJECTS)
	$(AR) $(TARGET).a $(OBJECTS)

$(TARGET).so: $(OBJECTS)
	$(CC) -shared $(OBJECTS) -o $(TARGET).so

#Musterregel
%.o:%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $<

#Abhängigkeiten
include depend