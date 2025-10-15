# Simple Makefile for Vector Calculator
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -MMD
TARGET = calc
SRCS = calc.c vectors.c
OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

-include $(DEPS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS) $(DEPS)
