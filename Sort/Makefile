.PHONY : all clean

CC = gcc
CFLAGS = -Wall -g

BIN = main
OBJS = main.o assist.o sort.o

all : $(BIN)

$(BIN) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(BIN) core.*
