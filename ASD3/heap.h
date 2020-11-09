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
			lot = data;
			S = new Stack();
			current = 0;
			S->push_back(current);
			deep_size = size;
			colored = new bool[deep_size];
			for (int i = 0; i < deep_size; i++) 
				colored[i] = false;
			done = 0;
		};
		int next() override;
		bool has_next() override;

	private:
		int current;
		Stack* S;
		bool* colored;
		int* lot;
		size_t deep_size;
		int done;
	};

	class WideIterator : public Iterator 
	{
	public:
		WideIterator(size_t size, int* data) {
			lot = data;
			current = 0;
			wide_size = size;
		};
		int next() override;
		bool has_next() override;
	private:
		int current;
		int* lot;
		size_t wide_size;
	};

private:
	void add_first(int newElem);
	void reset_heap();

	size_t heap_size;
	size_t max_size = 1000;
	int* data;
};