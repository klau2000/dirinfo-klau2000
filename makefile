all: main.o dirinfo.o
	gcc -o output main.o dirinfo.o

main.o: main.c dirinfo.c
	gcc -c main.c

dirinfo.o: dirinfo.c dir.h
	gcc -c dirinfo.c

dir.o: dir.c dir.h
	gcc -c dir.c

run:
	./output

clean:
	rm *.o
	rm *~
