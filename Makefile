CC = gcc
CFLAGS = -Ofast -Wall -Wextra -g3 -std=gnu18
LDFLAGS =  -lm
FILES = pwd.c utils.c
OBJECTS = pwd.o utils.o

pwd: $(OBJECTS)
	gcc -o $@ $^ $(LDFLAGS) $(CFLAGS)

%.o: %.c
	gcc -c $(CFLAGS) $^ -o $@

clean:
	rm -f *.o
