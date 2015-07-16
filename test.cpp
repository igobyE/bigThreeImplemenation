#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "StackArray.h"

int main (int argc, char** argv) {
	if (argc < 2) {
		exit (1);
	}
	srand (time (NULL));

	StackArray aStack = StackArray ();
	std::cout << "size: " << aStack.getSize () << "\n";
	std::cout << "cap: " << aStack.getCap () << "\n";

	int size = std::stoi (argv[1]);
	for (int i=0; i<size; ++i) {
		aStack.push (rand () % 100 +1);
	}
	std::cout << "size: " << aStack.getSize () << "\n";
	std::cout << "cap: " << aStack.getCap () << "\n";
	aStack.print ();

	for (int i=0; i<size/2; ++i) {
		aStack.pop ();
	}
	std::cout << "size: " << aStack.getSize () << "\n";
	std::cout << "cap: " << aStack.getCap () << "\n";
	aStack.print ();

	StackArray copyStack = StackArray (aStack);
	std::cout << "copyStack: size: " << copyStack.getSize () << "\n";
	std::cout << "copyStack: cap: " << copyStack.getCap () << "\n";
	copyStack.print ();

	StackArray assStack = copyStack;
	std::cout << "assStack: size: " << assStack.getSize () << "\n";
	std::cout << "assStack: cap: " << assStack.getCap () << "\n";
	assStack.print ();

	return 0;
}