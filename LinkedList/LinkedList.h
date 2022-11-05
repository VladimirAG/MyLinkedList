#pragma once
#include "Node.h"

class LinkedList {
public:
	Node* head, * tail;
	LinkedList();
	~LinkedList();

	void push_back(int data);

	void push_front(int data);

	void pop_front();

	void pop_back();

	Node* get_elem(int n);

	void insert(int idx, int data);

	void erase(int idx);
};