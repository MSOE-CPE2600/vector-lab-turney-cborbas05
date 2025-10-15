# Vector Calculator Project - Makefile

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -MMD -MP
TARGET = calc
SRCS = calc.c vectors.c
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS) $(TARGET)

rebuild: clean all
