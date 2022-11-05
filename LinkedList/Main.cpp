#include <iostream>
#include "LinkedList.h"
#include "Node.h";

using namespace std;

int main() {
	LinkedList lst;
	lst.push_front(2);
	lst.push_front(7);
	lst.push_back(5);
	lst.insert(1, 3);

	Node* elem = lst.get_elem(2);
	int d = (elem != NULL) ? elem->data : 0;
	cout << d << endl;
	for (Node* node = lst.head; node != NULL; node = node->next)
		cout << node->data << " ";
	cout << endl;
	return 0;
}