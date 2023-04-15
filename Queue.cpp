#include "Queue.h"

Queue::Queue() {
	first = nullptr;
	last = nullptr;
	count = 0;
}

Queue::~Queue() {

}

// Adding something to the Queue
void Queue::enQueue(int value) {
	// Create the node
	Node* newNode = new Node;
	newNode->value = value;
	newNode->nextPtr = nullptr;
	// adding to an empty list
	if (isEmpty()) {
		first = newNode;
		last = newNode;
	}
	// Adding to the end of a non-empty list
	else {
		last->nextPtr = newNode;
		last = newNode;
	}
	this->count++;
}

void Queue::deQueue() {
	// If theres nothing, do nothing
	if (isEmpty()) {
		return;
	}
	// We want to move first to the next node
	Node* tempPtr = first;
	first = first->nextPtr;
	delete tempPtr;
	tempPtr = nullptr;
	this->count--;
}

void Queue::printQueue() {
	Node* tempPtr = first;
	while (tempPtr != nullptr) {
		cout << tempPtr->value << endl;
		tempPtr = tempPtr->nextPtr;
	}
}


// Simply returns the front of the queue
Node* Queue::front()
{
	return first;
}

bool Queue::isEmpty()
{
	if (this->first == nullptr)
	{
		return true;
	}
	else return false;
}

int Queue::size()
{
	return this->count;
}