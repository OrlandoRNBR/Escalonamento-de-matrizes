CC = gcc
CFLAGS = -Wall -Wextra
LDLIBS = 

SRCS = main.c escal_matriz.c

OBJS = $(SRCS:.c=.o)

all: $(OBJS)
	$(CC) -o main.exe $(CFLAGS) $(OBJS) $(LDLIBS)
