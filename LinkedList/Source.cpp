#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

class LinkedList {
public:
	Node* head, * tail;
	LinkedList() {
		this->head = this->tail = NULL;
	}

	~LinkedList() {
		while (head != NULL) pop_front();
	}

	void push_back(int data) {
		Node* node = new Node(data);
		if (head == NULL) head = node;
		if (tail != NULL) tail->next = node;
		tail = node;
	}

	void push_front(int data) {
		Node* node = new Node(data);
		node->next = head;
		head = node;
		if (tail == NULL) tail = node;
	}

	void pop_front() {
		if (head == NULL) return;
		if (head == tail) {
			delete tail;
			head = tail = NULL;
			return;
		}
		Node* node = head;
		head = node->next;
		delete node;
	}

	void pop_back() {
		if (tail == NULL) return;
		if (head == tail) {
			delete tail;
			head = tail = NULL;
			return;
		}
		Node* node = head;
		while (node->next != tail) node = node->next;
		node->next = NULL;
		delete tail;
		tail = node;
	}

	Node* get_elem(int n) {
		if (n < 0) return NULL; 
		int idx = 0;
		Node* node = head;
		while (node && idx < n && node->next) {
			node = node->next;
			++idx;
		}
		return (idx == n) ? node : NULL;
	}

	void insert(int idx, int data) {
		Node* left = get_elem(idx);
		if (left == NULL) return; 
		Node* right = left->next;
		Node* node = new Node(data);
		left->next = node;
		node->next = right;
		if (right == NULL)  tail = node;
	}

	void erase(int idx) {
		if (idx < 0) return;
		if (idx == 0) {
			pop_front();
			return;
		}
		Node* left = get_elem(idx - 1);
		Node* node = left->next;
		if (left->next == NULL) return;
		Node* right = node->next;
		left->next = right;
		if (node == tail) tail = left;
		delete node;

	}
};

int main() {
	LinkedList lst;
	lst.push_front(2);
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