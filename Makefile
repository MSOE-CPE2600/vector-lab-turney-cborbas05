# Vector Calculator Project - Makefile
CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = calc
SRCS = calc.c vectors.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)

rebuild: clean all
