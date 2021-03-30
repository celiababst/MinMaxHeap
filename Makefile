lab6: main.o minmax.o
	g++ main.o minmax.o -o lab6

main.o: main.cpp minmax.h
	g++ -c main.cpp

minmax.o: minmax.cpp minmax.h
	g++ -c minmax.cpp

clean:
	rm -f lab6 *.o
