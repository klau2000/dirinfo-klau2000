all: main.o dirinfo.o
	gcc -o output main.o dirinfo.o

main.o: main.c dirinfo.c
	gcc -c main.c

dirinfo.o: dirinfo.c dirinfo.h
	gcc -c dirinfo.c

rand.o: dirinfo.c dirinfo.h
	gcc -c dirinfo.c

run:
	./output

clean:
	rm *.o
	rm *~
