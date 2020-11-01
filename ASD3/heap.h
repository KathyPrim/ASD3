#pragma once
#include<iostream>
//#include"Iterator.h"
#include"Stack.h"

class heap
{
public:
	heap(int newData);
	~heap();
	void swap(int number1, int number2);
	bool contaains(int elem);
	void insert(int newElem);
	void print();
	
	//Iterator create_dft_iterator(); // deep-first
	//Iterator create_bft_iterator(); // breadth-first
	//class DeepIterator : public Iterator
	//{
	//public:
	//	DeepIterator(int start);
	//	int next() override;
	//	bool has_next() override;

	//private:
	//	int current;
	//	Stack* S;
	//	bool* deep;
	//	int size;
	//};

	//class WideIterator : public Iterator 
	//{
	//public:
	//	WideIterator(int start);
	//	int next() override;
	//	bool has_next() override;
	//private:
	//	int current;
	//};


private:
	void add_first(int newElem);
	void reset_heap();

	size_t size;
	static const size_t max_size = 100;
	int* data;
};

heap::heap(int newData)
{
	this->data = new int[max_size];
	data[0] = newData;
	this->size = 1;
}

heap::~heap()
{
	delete this->data;
	size = 0;
}