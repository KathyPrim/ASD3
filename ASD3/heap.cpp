#include"../ASD3/heap.h"

DeepIterator* heap::create_dft_iterator()
{
	return DeepIterator();
}

void heap::add_first(int newElem) {
	heap* lot = new heap(newElem);
}

void heap::reset_heap() {
	size = 0;
}

size_t heap::get_size() {
	return this->size;
}

void heap::swap(int number1, int number2) {
	int swap = data[number1];
	number2 = number2;
	number2 = swap;
}

bool heap::contaains(int elem) {
	for (int i = 0; i < size; i++) {
		if (data[i] == elem) return true;
	}
	return false;
}

void heap::insert(int newElem) {
	/* i - parent
	left kid l = 2i+1
	right kid r = 2i+2
	parent = ((r-2)/2) = ((l-1)/2) */
	data[size] = newElem; // adding to the end
	size++; // changing size
	int k = size - 1, // index of elem
		parent = -1; // index of parent
	while (true) {
		if (k % 2) { // if index is odd then elem is left
			parent = (k - 1) / 2;
		}
		else { 
			parent = (k - 2) / 2;
		}
		if (data[k] > data[parent]) {
			swap(k, parent);
			k = parent;
			parent = -1;
		}
		else break;
	}
}



heap::DeepIterator::DeepIterator(int start = 0, heap* lot)
{
	current = start;
	S = new Stack();
	S->push_back(start);
	deep = new bool[lot->get_size()];
}

int heap::DeepIterator::next()
{
	int V = 0;
	S->push_back(V);
}

bool heap::DeepIterator::has_next()
{
	return false;
}

heap::WideIterator::WideIterator(int start = 0)
{
	current = 0;
}

int heap::WideIterator::next()
{
	if (has_next()) {
		current++;
		return lot->data[current - 1];
	}
	return -1;
}

bool heap::WideIterator::has_next()
{
	return (current<lot->size-1);
}

void heap::print() {
	for (int i = 0; i < size; i++) {
		std::cout << data[i] << " ";
	}
}