#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList() : head(NULL), tail(NULL) {}

LinkedList::~LinkedList() {
	while (head != NULL) pop_front();
}

void LinkedList::push_back(int data) {
	Node* node = new Node(data);
	if (head == NULL) head = node;
	if (tail != NULL) tail->next = node;
	tail = node;
}

void LinkedList::push_front(int data) {
	Node* node = new Node(data);
	node->next = head;
	head = node;
	if (tail == NULL) tail = node;
}

void LinkedList::pop_front() {
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

void LinkedList::pop_back() {
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

Node* LinkedList::get_elem(int n) {
	if (n < 0) return NULL;
	int idx = 0;
	Node* node = head;
	while (node && idx < n && node->next) {
		node = node->next;
		++idx;
	}
	return (idx == n) ? node : NULL;
}

void LinkedList::insert(int idx, int data) {
	Node* left = get_elem(idx);
	if (left == NULL) return;
	Node* right = left->next;
	Node* node = new Node(data);
	left->next = node;
	node->next = right;
	if (right == NULL)  tail = node;
}

void LinkedList::erase(int idx) {
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