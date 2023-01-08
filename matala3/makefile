all: isort txtfind

isort: isort.o
	gcc -Wall isort.o -o isort

txtfind: txtfind.o
	gcc -Wall txtfind.o -o txtfind

isort.o: isort.c
	gcc -Wall -c isort.c

txtfind.o: txtfind.c
	gcc -Wall -c txtfind.c

clean:
	rm -f *.o isort txtfind