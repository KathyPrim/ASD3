#include "Stack.h"

void Stack::reset_stack()
{
	tail = nullptr;
	stack_size = 0;
}

void Stack::stack_add_first(int newElem)
{
	tail = new SNode(newElem);
}

void Stack::push_back(int newElem)
{
	if (stack_size == 0) {
		stack_add_first(newElem);
	}
	else {
		SNode* tmp = new SNode(newElem);
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
		SNode* current = tail->prev;
		delete tail;
		tail = current;
		stack_size--;
	}
}

bool Stack::isEmpty()
{
	return (stack_size==0);
}

int Stack::return_last()
{
	return tail->data;
}
