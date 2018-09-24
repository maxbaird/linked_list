PROJECT       = list.o
CC            = gcc
CFLAGS        = -Wall -Werror -Wextra

.PHONY : clean all

all : $(PROJECT)

$(PROJECT) : list.c
	$(CC) $(CFLAGS) -c $< 

demo.out : demo.c $(PROJECT)
	$(CC) $(CFLAGS) $< $(PROJECT) -o $@ 

clean:
	rm -rf *.o *.out $(PROJECT)
