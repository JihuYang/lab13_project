CC = gcc
CFLAGS = -W -Wall
TARGET = flea
OBJECTS = fleamarket.c fleamarket.h manage.o

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS)  -o $@ $^

clear :
	rm *.o flea
