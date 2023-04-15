#pragma
#include <iostream>
using namespace std;

struct Node {
	int value;
	Node* nextPtr;
};

class Queue
{
public:
	// Constructors / Destructors
	Queue();
	~Queue();
	// Functions
	void enQueue(int value);
	void deQueue();
	void printQueue();
	Node* front();
	bool isEmpty();
	int size();
private:
	Node* first; // First in line
	Node* last; // Last in line. points to the end
	int count = 0;
};
