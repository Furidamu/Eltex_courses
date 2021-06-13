CC := gcc
creat :=  mkdir -p bin build/src dynamiclib

all: dynamiclib/libdynamic 

folder:
	$(creat)

dynamiclib/libdynamic: folder build/src/main.o build/src/division.o build/src/menu.o build/src/minus.o build/src/plus.o build/src/multiplication.o
	#$(CC) build/src/main.o build/src/division.o build/src/menu.o build/src/minus.o build/src/plus.o build/src/multiplication.o -o bin/calculator
	$(CC) -shared -odynamiclib/libdynamic.so build/src/main.o build/src/division.o build/src/menu.o build/src/minus.o build/src/multiplication.o build/src/plus.o
	
build/src/main.o: src/main.c
	$(CC) -fPIC -c src/main.c -o build/src/main.o

build/src/division.o: src/division.c
	$(CC) -fPIC -c src/division.c -o build/src/division.o

build/src/menu.o: src/menu.c
	$(CC) -fPIC -c src/menu.c -o build/src/menu.o

build/src/minus.o: src/minus.c
	$(CC) -fPIC -c src/minus.c -o build/src/minus.o

build/src/multiplication.o: src/multiplication.c
	$(CC) -fPIC -c src/multiplication.c -o build/src/multiplication.o

build/src/plus.o: src/plus.c
	$(CC) -fPIC -c src/plus.c -o build/src/plus.o

test:bin/test

bin/test: 
	gcc test/testDynamiclib.c -o bin/test -L/dynamiclib/ -ldynamic

.PHONY: clean

clean:
	rm -rf build/src/*.o
