#pragma once
#include <iostream>

using namespace std;

template <typename T>
class DLL {
public:
	DLL() : head_(nullptr), tail_(nullptr) {}
	~DLL();
	void pushFront(const T&);
	// Public recursive print. This is the function that will be called by usrs:
	void rec_print();
	void pushBack(const T&);
	void popFront();
	void popBack();
	bool empty();
	int rec_size();
	T operator[](const int);
	bool rec_find(const T&);
	
private:
	class DNode {
	public:
		const T& data;
		DNode* next;
		DNode* prev;
		DNode(const T& d) : data(d), next(nullptr), prev(nullptr) {}
	};
	DNode* head_;
	DNode* tail_;
	// Private recursive print. This is an auxiliary function.
	void rec_p(DNode*);
	int rec_s(DNode*);
	bool rec_f(const T&, DNode*);
};

template<typename T>
DLL<T>::~DLL() {
	while (head_ != nullptr) {
		popFront();
	}
}

template <typename T>
void DLL<T>::pushFront(const T& d) {
	DNode* newNode = new DNode(d);
	if (head_ == nullptr) {
		head_ = newNode;
		tail_ = newNode;
	}
	else {
		head_->prev = newNode;
		newNode->next = head_;
		head_ = newNode;
	}
}

template <typename T>
void DLL<T>::rec_p(DNode* ptr) {
	if (ptr != nullptr) {
		cout << ptr->data << " ";
		rec_p(ptr->next);
	}
}

template <typename T>
void DLL<T>::rec_print() {
	rec_p(head_);
	cout << endl;
}

template<typename T>
int DLL<T>::rec_s(DNode* ptr) {
	if (ptr != nullptr) {
		return rec_s(ptr->next) + 1;
	}
	return 0;
}

template<typename T>
int DLL<T>::rec_size() {
	return rec_s(head_);
}

template<typename T>
bool DLL<T>::rec_f(const T& i, DNode* ptr) {
	if (ptr == nullptr) {
		return false;
	}
	if (ptr->data == i) {
		return true;
	}
	else
	{
		return rec_f(i, ptr->next);
	}
}

template<typename T>
bool DLL<T>::rec_find(const T& i) {
	return rec_f(i, head_);
}

template <typename T>
void DLL<T>::pushBack(const T& d) {
	DNode* newNode = new DNode(d);
	newNode->next = nullptr;

	if (head_ == nullptr) {
		head_ = newNode;
		tail_ = newNode;
	}
	else {
		tail_->next = newNode;
		newNode->prev = tail_;
		tail_ = newNode;
	}
	
}

template<typename T>
void DLL<T>::popFront() {
	if (head_ == nullptr) {
		return;
	}
	else {
		DNode* temp = head_;
		head_ = head_->next;
		delete[] temp;
	}
}

template<typename T>
void DLL<T>::popBack() {
	if (head_ == nullptr) {
		return;
	}
	else {
		DNode* temp = tail_;
		tail_ = tail_->prev;
		tail_->next = nullptr;
		delete[] temp;
	}
}

template<typename T>
bool DLL<T>::empty() {
	if (head_ == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
T DLL<T>::operator[](const int i) {
	if (i <= rec_size() && i >= 0) {
		DNode* ptr = head_;
		for (int j = 0; j < i; j++) {
			ptr = ptr->next;
		}
		return ptr->data;
	}
	return tail_->data;
}