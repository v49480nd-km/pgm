CC = gcc
CFLAGS = -Ofast -Wall -Wextra -g3 -std=gnu18
LDFLAGS =  -lm
FILES = main.c utils.c
OBJECTS = main.o utils.o

pwd: $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS) $(CFLAGS)

%.o: %.c
	$(CC) -c $(CFLAGS) $^ -o $@

clean:
	rm -f *.o
