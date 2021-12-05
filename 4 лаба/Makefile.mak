
Fourth : fourth.o utils.o
	gcc fourth.o utils.o -o Fourth

fourth.o : fourth.c
	gcc -c fourth.c -o fourth.o

utils.o : utils.c
	gcc -c utils.c -o utils.o

clean: 
	rm Fourth *.o