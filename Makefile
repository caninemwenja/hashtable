TARGET=hasher
DEBUG_TARGET=hasher_dbg
CC=gcc
CFLAGS=-O2 -W -Wall -pedantic
DEBUGFLAGS=-ggdb
LIBS=

OBJECTS=$(patsubst %.c, %.o, $(wildcard *.c))
HEADERS=$(wildcard *.h)
SOURCES=$(wildcard *.c)

.PHONY: default all clean debug

default: $(TARGET)
all: default


$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBS) -o $@


%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

debug:
	$(CC) $(CFLAGS) $(SOURCES) $(DEBUGFLAGS) $(LIBS) -o $(DEBUG_TARGET)


clean:
	rm -f *.o
	rm -f $(TARGET)
	rm -f $(DEBUG_TARGET)
