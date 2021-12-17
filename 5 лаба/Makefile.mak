Fifth : fifth.o utils.o
	gcc fifth.o utils.o -o Fifth

fifth.o : fifth.c
	gcc -c fifth.c -o fifth.o

utils.o : utils.c
	gcc -c utils.c -o utils.o

clean: 
	rm Fifth *.o

