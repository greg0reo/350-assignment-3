all: main

main: main.o work.o
	g++ main.o work.o -o main.exe

main.o: main.cpp
	g++ -g -c main.cpp

work.o: work.cpp work.h
	g++ -g -c work.cpp

clean:
	rm -f *.o	
