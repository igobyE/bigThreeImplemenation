/************************************************
*	It got The Big Three (Custrom copy constructor, destructor, and assignemnt operator)
*	http://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom
************************************************/

#include <iostream>

#include "StackArray.h"

StackArray::StackArray () : data (NULL), size (0), cap (10) {
	create ();
}

StackArray::~StackArray () {
	destroy ();
}

StackArray::StackArray (const StackArray& other) {
	if (this != &other) {
		size = other.size;
		cap = other.cap;
		data = new int [other.cap];
		std::copy (other.data, other.data+size, data);
	}
}

StackArray& StackArray::operator= (StackArray other){
	if (this != &other) {
		swap (*this, other);
	}

	return *this;
}

bool StackArray::create () {
	data = new int [cap];
	memset (data, 0, cap*sizeof (int));
	return true;
}

void StackArray::destroy () {
	delete[] data;
	data = NULL;
}

bool StackArray::expand () {
	cap *= 2;
	int* tmp = new int [cap];
	memcpy (tmp, data, size*sizeof (int));

	destroy ();
	data = tmp;
	tmp = NULL;

	return true;
}

void StackArray::swap (StackArray& one, StackArray& two) {
	using std::swap;

	swap (one.size, two.size);
	swap (one.cap, two.cap);
	swap (one.data, two.data);
}

bool StackArray::isEmpty () {
	if (size == 0) {
		return true;
	}
	return false;
}

bool StackArray::isFull () {
	if (size == cap) {
		return true;
	}
	return false;
}

bool StackArray::push (const int& i) {
	if (isFull ()) {
		std::cout << "Expanding\n";
		expand ();
	}
	data[size] = i;

	size += 1;
	return true;
}

int StackArray::pop () {
	size -= 1;
	return data[size];
}

int StackArray::peak () {
	return data[size-1];
}

int StackArray::getSize () {
	return size;
}

int StackArray::getCap () {
	return cap;
}

void StackArray::print () {
	for (int i=0; i<size; ++i) {
		std::cout << data[i] << " ";
		if ((i+1) % 20 == 0)
			std::cout << "\n";
	}
	std::cout << "\n";
}