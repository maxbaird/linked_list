#	Makefile by Max Baird
#	Sun 17 June 2017 01:45:42 GMT

CC			= gcc
CFLAGS 	= -Wall -Werror -Wextra
PROJECT = list.o

.PHONY : clean all

all : $(PROJECT)

$(PROJECT) : list.c
	$(CC) $(CFLAGS) -c $< 

test : test.c $(PROJECT)
	$(CC) $(CFLAGS) $< $(PROJECT) -o $@ 

clean:
	rm -rf *.o test $(PROJECT)
