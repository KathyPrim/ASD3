#pragma once
class Stack
{
private:
	void stack_add_first(int newElem);
	void reset_stack();

	class SNode
	{
	public:
		SNode(int data, SNode* prev = nullptr) {
			this->data = data;
			this->prev = prev;
		};
		~SNode() {};

		int data;
		SNode* prev;
	};

	SNode* tail;
	size_t stack_size;

public:

	Stack()
	{
		reset_stack();
	};

	~Stack()
	{
		if (tail) {
			while (tail->prev) {
				pop_back();
			}
			reset_stack();
		}
	};

	void push_back(int newElem);
	void pop_back();
	bool isEmpty();
	int return_last();
};