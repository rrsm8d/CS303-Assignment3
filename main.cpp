//#include "Functions.h"
#include "Infix.h"
#include "Queue.h"

char printMenu()
{
	cout << endl << "What would you like to do?" << endl << endl;
	cout << "C - Convert infix to postfix" << endl;
	cout << "I - Insert new element in Queue" << endl;
	cout << "R - Remove element at Queue front" << endl;
	cout << "F - Print the front element of the Queue" << endl;
	cout << "E - Check if queue is empty" << endl;
	cout << "T - Prints total number of items in Queue" << endl;
	cout << "P - Print the full Queue" << endl;
	cout << "Q - Quit" << endl;
	char sel;
	cin >> sel;
	return toupper(sel);

}



int main() {
	string inFix;
	int input;
	Queue queue;

	char sel = 'x';
	while (sel != 'Q')
	{
		sel = printMenu();
		switch (sel)
		{
			case 'C':
				cout << "Enter an expression to convert to postfix [ Example: (A+B*(C-D))/E ]: ";
				cin >> inFix;
				cout << endl << inFix << "  ----->  " << convert(inFix) << endl;
				break;
			case 'I':
				cout << "Enter a number to instert into the Queue: ";
				cin >> input;
				queue.enQueue(input);
				break;
			case 'R':
				if (!queue.isEmpty())
				{
					queue.deQueue();
				}
				else cout << "Queue is empty! Cannot remove anything!" << endl;
				break;
			case 'F':
				if (!queue.isEmpty())
				{
					cout << "Value: " << queue.front()->value << endl;
				}
				else cout << "Queue is empty! Cannot print anything!" << endl;
				break;
			case 'E':
				if (queue.isEmpty())
				{
					cout << endl <<"Queue is empty" << endl;
				}
				else cout << endl << "Queue is NOT empty" << endl;
				break;
			case 'T':
				cout << endl << "Size: " << queue.size() << endl;
				break;
			case 'P':
				cout << endl;
				queue.printQueue();
				break;
			case 'Q':
				break;
			default:
				cout << "Invalid choice" << endl;
				break;
		}
	}
	return 0;
}