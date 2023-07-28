CPP = g++
CPPFLAGS = -Wall -Wextra -pedantic -std=c++11 -g -fPIE

quicksort: main.o
	$(CPP) $(CPPFLAGS) -o quicksort main.o

main.o: main.cpp
	$(CPP) $(CPPFLAGS) -c main.cpp

clean: rm -f quicksort *.o *~
