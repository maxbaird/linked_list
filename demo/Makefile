PROJECT       = demo.out
CC            = gcc
CFLAGS        = -c -Wall -Werror -Wextra

.PHONY : clean all

all : $(PROJECT)

$(PROJECT) : demo.o list.o
	$(CC) $^ -o $@ 

demo.o : demo.c
	$(CC) $(CFLAGS) $< -o $@ 

list.o : ../list.c
	$(CC) $(CFLAGS) $< -o $@ 

clean:
	rm -rf *.o $(PROJECT)
