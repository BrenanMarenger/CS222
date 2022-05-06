#include"MaxHeap.h"
#include<iostream>
#include"assert.h"

using namespace std;

int main() {
	MaxHeap h1;
	h1.insert(7);
	h1.insert(3);
	h1.insert(10);
	h1.insert(5);
	assert(h1.getMax() == 10);
	assert(h1.extractMax() == 10);
	assert(h1.getMax() == 7); 
	h1.insert(15);
	h1.insert(8);
	h1.insert(1);
	assert(h1.extractMax() == 15);
	assert(h1.getMax() == 8);
	assert(h1.extractMax() == 8);
	assert(h1.getMax() == 7);
	assert(h1.extractMax() == 7);
	assert(h1.getMax() == 5);
	h1.insert(50);
	assert(h1.extractMax() == 50);

	return 0;
}