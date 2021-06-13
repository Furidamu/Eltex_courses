CC := gcc
creat :=  mkdir -p bin build/src staticlib

all: bin/calculator staticlib/libMy.a

folder:
	$(creat)

bin/calculator: folder build/src/mn.o build/src/calculation.o
	#$(CC) build/src/mn.o build/src/calculation.o -o bin/calculator
	ar rc staticlib/libMy.a build/src/mn.o build/src/calculation.o

build/src/mn.o: src/mn.c
	$(CC) -c src/mn.c -o build/src/mn.o

build/src/calculation.o: src/calculation.c
	$(CC) -c src/calculation.c -o build/src/calculation.o

test:bin/test
	
bin/test:
	gcc test/testStaticlib.c staticlib/libMy.a -o bin/test

.PHONY: clean

clean:
	rm -rf build/src/*.o
	rm -rf bin/*
	rm -rf staticlib/*
	
