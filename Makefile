CC=clang
CFLAGS=-std=c17 -O3 -Werror -Wextra -Wall -Wfloat-equal -Wundef -Wshadow \
	   -Wformat=2 -Wpedantic
SRC=src
OBJ=obj
SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
BIN=bin/pgm

all: $(BIN)

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	rm obj/*.o
