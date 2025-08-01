exe: main.o string.o my_own_str.o
	c++ main.o string.o my_own_str.o -o exe

main.o: main.cpp header.h
	c++ -c main.cpp

string.o: string.cpp header.h
	c++ -c string.cpp

my_own_str.o: my_own_str.cpp header.h
	c++ -c my_own_str.cpp

clean:
	rm -f *.o exe
