.SUFFIXES:.c .o
CC=gcc
SRCS=main.c\
    test.c
OBJS=$(SRCS:.c=.o)
EXEC=main.exe
 
build:$(OBJS)
    $(CC) -o $(EXEC) $(OBJS)
    @echo '---------------OK---------------'
 
.c.o:
    $(CC) -Wall -g -o $@ -c $<
 
clean:
    del $(OBJS)
    del $(EXEC)