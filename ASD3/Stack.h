#pragma once
class Stack
{
private:
	void add_first(int newElem);
	void reset_stack();

	class Node
	{
	public:
		Node(int data, Node* prev = nullptr) {
			this->data = data;
			this->prev = prev;
		};
		~Node() {};

		int data;
		Node* prev;
	};

	Node* tail;
	size_t stack_size;

public:

	Stack();
	~Stack();

	void push_back(int newElem);
	void pop_back();
	bool isEmpty();
};