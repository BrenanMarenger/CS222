#include"MaxHeap.h"
#include<iostream>

MaxHeap::MaxHeap() {
	capacity_ = 2; 
	size_ = 0; 
	items_ = new int[capacity_ + 1];
}

int MaxHeap::_parent(int i) {
	return i / 2;
}
int MaxHeap::_rightChild(int i) {
	return (2 * i) + 1;
}
int MaxHeap::_leftChild(int i) {
	return 2 * i;
}
int MaxHeap::getMax() {
	return items_[1];
}

void MaxHeap::insert(int k) {
	if (size_ == capacity_) {
		_doubleArray();
	}
	size_++;
	items_[size_] = k;
	_heapifyUp(size_);
}

void MaxHeap::_doubleArray() {
	capacity_ = capacity_ * 2;
	int* temp = items_; 
	items_ = new int[capacity_+1];
	for (int i = 1; i <= size_; i++) {
		items_[i] = temp[i];
	}
	delete[] temp; 
	temp = nullptr;
}

void MaxHeap::_heapifyUp(int i) {
	if (i > 1 && items_[_parent(i)] < items_[i]) {
		_swap(_parent(i), i);
		_heapifyUp(_parent(i));
	}
}

void MaxHeap::_swap(int i, int j) {
	int temp = items_[i];
	items_[i] = items_[j];
	items_[j] = temp;
}

int MaxHeap::extractMax() {
	int result = items_[1];
	items_[1] = items_[size_];
	size_--;
	_heapifyDown(1);
	return result;
}

bool MaxHeap::_isLeaf(int i) { //?
	if (i <= size_ && _rightChild(i) > size_ && _leftChild(i) > size_) {
		return true;
	}
	else {
		return false;
	}
}

void MaxHeap::_heapifyDown(int i) { //?
	if (!_isLeaf(i)) {
		int maxIndex = i;
		int l = _leftChild(i);
		if (l <= size_ && items_[l] > items_[maxIndex]) {
			maxIndex = l;
		}
		int r = _rightChild(i);
		if (r <= size_ && items_[r] > items_[maxIndex]) {
			maxIndex = r;
		}
		if (maxIndex != i) {
			_swap(i, maxIndex);
		}
		_heapifyDown(maxIndex);
	}
}

MaxHeap::~MaxHeap() {
	delete[] items_;
	items_ = nullptr;
}