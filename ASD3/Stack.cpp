#include "Stack.h"

void Stack::reset_stack()
{
	tail = nullptr;
	stack_size = 0;
}

Stack::Stack()
{
	reset_stack();
}

Stack::~Stack()
{
	if (tail) {
		while (tail->prev) {
			pop_back();
		}
		reset_stack();
	}
}

void Stack::add_first(int newElem)
{
	tail = new Node(newElem);
}

void Stack::push_back(int newElem)
{
	if (stack_size == 0) {
		add_first(newElem);
	}
	else {
		Node* tmp = new Node(newElem);
		tmp->prev = tail;
		tail = tmp;
	}
	stack_size++;
}

void Stack::pop_back()
{
	if (stack_size == 1) {
		delete tail;
		reset_stack();
	}
	else {
		Node* current = tail->prev;
		delete tail;
		tail = current;
		stack_size--;
	}
}

bool Stack::isEmpty()
{
	return (stack_size==0);
}
