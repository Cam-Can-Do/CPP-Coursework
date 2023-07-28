CPP = g++
CPPFLAGS = -Wall -Wextra -pedantic -std=c++11 -g

radix-bucket: main.o
	$(CPP) $(CPPFLAGS) -o radix-bucket main.o

main.o: main.cpp
	$(CPP) $(CPPFLAGS) -c main.cpp

clean: rm -f radix-bucket *.o *~
