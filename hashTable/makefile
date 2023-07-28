CPP = g++
CPPFLAGS = -Wall -Wextra -pedantic -std=c++11 -g

p5: main.o hashTable.o
	$(CPP) $(CPPFLAGS) -o p5 main.o hashTable.o

main.o: main.cpp hashTable.h
	$(CPP) $(CPPFLAGS) -c main.cpp

intMinHeap.o: hashTable.cpp hashTable.h

clean:
	rm -f p5 *.o *~
