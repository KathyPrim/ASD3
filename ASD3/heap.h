#pragma once
#include<iostream>
#include"Iterator.h"
#include"Stack.h"

using namespace std;

class heap
{
public:
	heap(int newData)
	{
		this->data = new int[max_size];
		data[0] = newData;
		this->heap_size = 1;
	};
	~heap() {
		delete this->data;
		heap_size = 0;
	};
	size_t get_size();
	void swap(int number1, int number2);
	void shiftUp(int k);
	void shiftDown(int k);
	bool contains(int elem);
	void insert(int newElem);
	void remove(int elem);
	void print();
	int min_data(int a, int b);

	Iterator* create_dft_iterator(); // deep-first
	Iterator* create_bft_iterator(); // breadth-first
	
	class DeepIterator : public Iterator
	{
	public:
		DeepIterator(size_t size, int* data) {
			deep_lot->data = data;
			deep_lot->heap_size = size;
			//lot = data;
			S = new Stack();
			S->push_back(0);
			//deep_size = size;
			colored = new bool[deep_lot->heap_size];
			for (int i = 0; i < deep_lot->heap_size; i++)
				colored[i] = false;
		};
		int next() override;
		bool has_next() override;

	private:
		Stack* S;
		bool* colored;
		heap* deep_lot;
	};

	class WideIterator : public Iterator 
	{
	public:
		WideIterator(size_t size, int* data) {
			wide_lot->data = data;
			wide_lot->heap_size = size;
			current = 0;
		};
		int next() override;
		bool has_next() override;
	private:
		int current;
		heap* wide_lot;
	};

private:
	void add_first(int newElem);
	void reset_heap();

	size_t heap_size;
	size_t max_size = 1000;
	int* data;
};