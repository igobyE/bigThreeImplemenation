class StackArray {
private:
	int* data;
	int size;
	int cap;
	bool create ();
	void destroy ();
	bool expand ();
	void swap (StackArray&, StackArray&);

public:
	StackArray ();
	~StackArray ();
	StackArray (const StackArray&);
	StackArray& operator= (StackArray);

	bool isEmpty ();
	bool isFull ();
	bool push (const int&);
	int pop ();
	int peak ();
	int getSize ();
	int getCap ();
	void print ();

};