CC = gcc -c
LD = gcc
CFLAGS = --std=c99

SOURCES = $(shell echo *.c)
HEADERS = $(shell scho *.h)
OBJECTS = $(SOURCES:.c=.o)
TARGET = lorenz

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(LD) $(OBJECTS) -o $@
	
%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean :
	rm -f $(TARGET) $(OBJECTS) *.out
