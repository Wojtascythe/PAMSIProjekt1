CPP=g++
CPPFLAG=-std=c++11 -c

program: main.o
	$(CPP) main.o -o program

main.o: main.cpp kolejka.h
	$(CPP) $(CPPFLAG) main.cpp -o main.o
