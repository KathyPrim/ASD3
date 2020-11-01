#include <iostream>
#include"heap.h"

int main()
{
	heap* h = new heap(0);
	h->insert(1);
	h->insert(2);
	h->print();
}