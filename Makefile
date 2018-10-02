SRC=linked_list.c
CC=gcc
CFDEBUG= -D_GNU_SOURCE -Wall -Werror -ansi -O2 

ll: 
	$(CC) -g $(CFDEBUG) -o out.out $(SRC)
clean: 
	rm -f *.o *.out
