test: test.o StackArray.o
	g++ -o test test.cpp StackArray.o

StackArray.o: StackArray.h StackArray.cpp
	g++ -c StackArray.cpp

clean:
	*o test