#include"heap.h"

/* i - parent
	left kid l = 2i+1
	right kid r = 2i+2
	parent = ((r-2)/2) = ((l-1)/2) */

void heap::add_first(int newElem) {
	heap* lot = new heap(newElem);
}

void heap::reset_heap() {
	heap_size = 0;
}

int heap::min_data(int a, int b) { // compare data, retutn index of less element
	return (data[a] < data[b] ? a : b);
}

size_t heap::get_size() {
	return this->heap_size;
}

void heap::swap(int number1, int number2) {
	int swap = data[number1];
	data[number1] = data[number2];
	data[number2] = swap;
}

void heap::shiftUp(int k) // elem have to be upper than it is
{
	int parent = (k - 1) / 2;
	while ((data[k] < data[parent])&&(k<heap_size)) {
		if (k % 2) { // if index is odd then elem is left
			parent = (k - 1) / 2;
		}
		else {
			parent = (k - 2) / 2;
		}
		swap(k, parent);
		k++;
		parent = -1;
	}
}

void heap::shiftDown(int k = 0) // starting index
{
	int right = 2 * k + 2, left = 2 * k + 1; // indexes of left and right childs
	int least;
	while ((left < heap_size)&&(k<heap_size)) { // we have at least 1 child
		// 3 types: left < k, left is the only or left>k, right < k.
		if (right < heap_size) { // both children
			if (data[k] > data[left]) { // if non-ordered
				least = min_data(left, right);
				swap(least, k);
			}
			if (data[k] > data[right]) swap(right, k);
		}
		if (data[k] > data[left]) swap(k, left);
		k++;
		left = 2 * k + 1;
		right = 2 * k + 2;
	}
}

bool heap::contains(int elem) {
	for (int i = 0; i < heap_size; i++) {
		if (data[i] == elem) return true;
	}
	return false;
}

void heap::insert(int newElem) {
	if (heap_size > max_size) {
		int* p;
		p = (int*)realloc(data, (max_size * 2 + 1) * sizeof(int));
		max_size = max_size * 2 + 1;
		if (!p) {
			throw std::out_of_range("Allocation error");
			return;
		}
	}
	else {
		data[heap_size] = newElem; // adding to the end
		heap_size++; // changing size
		shiftUp((int)heap_size-1);
	}
}

void heap::remove(int elem)
{
	for (int i = 0; i < heap_size; i++) {
		if (data[i] == elem) {
			swap(i, (int)heap_size - 1); // swap elem_to_delete and last
			heap_size--;
			shiftDown(i);
			break;
		}
	}
}

Iterator* heap::create_dft_iterator()
{
	return new DeepIterator(heap_size, data);
}

Iterator* heap::create_bft_iterator()
{
	return new WideIterator(heap_size, data);
}

int heap::DeepIterator::next()
{
	int res;
	int left = current * 2 + 1, right = current * 2 + 2;
	while (done< deep_size)
	{
		if ((left < deep_size) && (!colored[left])) { // non-colored left child
			current = current * 2 + 1;
			left = current * 2 + 1; right = current * 2 + 2;
			S->push_back(current);
		}
		else if (( right< deep_size) && (!colored[right])) { // non-colored right child
			current = current * 2 + 2;
			left = current * 2 + 1; right = current * 2 + 2;
			S->push_back(current);
		}
		else break; // if no children
	}
	res = current;
	colored[res] = true;
	S->pop_back();
	if (res % 2) current = (current - 1) / 2;
	else current = (current - 2) / 2;
	done++;
	return lot[res];
}

bool heap::DeepIterator::has_next()
{
	return !(S->isEmpty());
}

int heap::WideIterator::next()
{
	current++;
	return lot[current - 1];
}

bool heap::WideIterator::has_next()
{
	return (current<wide_size);
}

void heap::print() {
	for (int i = 0; i < heap_size; i++) {
		std::cout << data[i] << " ";
	}
}