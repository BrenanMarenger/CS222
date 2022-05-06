#include<iostream>
#include <string>
#include"stdlib.h"
#include <windows.h> 


using namespace std;

template<typename T>
void bubbleSort(T a[], int size) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size - 1; j++) {
				if (a[j] > a[j + 1]) {
					T temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
		}
}

template<typename T>
void insertionSort(T a[], int size) {
	int key = 0;
	int temp = 0;
	for (int i = 0; i < size; i++) {
		key = a[i];
		temp = i - 1;
		while (temp >= 0 && a[temp] > key) {
			a[temp + 1] = a[temp];
			temp = temp - 1;
		}
		a[temp + 1] = key;
	}

}

template<typename T>
void merge(T a[], int begin, int mid, int end) {
	int n = end - begin + 1;
	T* temp = new T[n];
	int leftIndex = begin;
	int rightIndex = mid + 1;
	int tempIndex = 0;
	while (leftIndex <= mid && rightIndex <= end) {
		if (a[leftIndex] <= a[rightIndex]) {
			temp[tempIndex] = a[leftIndex];
			tempIndex++;
			leftIndex++;
		}
		else {
			temp[tempIndex] = a[rightIndex];
			tempIndex++;
			rightIndex++;
		}
	}
	while (leftIndex <= mid) {
		temp[tempIndex] = a[leftIndex];
		leftIndex++;
		tempIndex++;
	}
	while(rightIndex <= end) {
		temp[tempIndex] = a[rightIndex];
		rightIndex++;
		tempIndex++;
	}
	for (int i = 0; i < n; i++) {
		a[begin + i] = temp[i];
	}
	delete[] temp;
}

template<typename T>
void mergeSort(T a[], int begin, int end) {
	if (begin < end) {
		int middle = (begin + end) / 2;
		mergeSort(a, begin, middle);
		mergeSort(a, middle + 1, end);
		merge(a, begin, middle, end);
	}
}

template<typename T>
int partition(T a[], int begin, int end) {
	int pivot = a[end];
	int i = begin - 1;
	for (int j = begin; j <= end - 1; j++) {
		if (a[j] < pivot) {
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[end]);
	return i + 1;

}

template<typename T>
void quickSort(T a[], int begin, int end) {
	if (begin < end) {
		int p = partition(a, begin, end);
		quickSort(a, begin, p - 1);
		quickSort(a, p + 1, end);
	}
}


template<typename T>
void printArr(T a[], int size) {
	for (int i = 0; i < size; i++) {
		cout << a[i] << " ";
	}
	return;
}

int main() {

	LARGE_INTEGER frequency;
	LARGE_INTEGER t1, t2;
	double elapsedTime;

	QueryPerformanceFrequency(&frequency);

	int array1[100000];
	for (int i = 0; i < 100000; i++) {
		array1[i] = rand() % 1000;
	}

	QueryPerformanceCounter(&t1);

	quickSort(array1, 0, 99999);

	QueryPerformanceCounter(&t2);
	cout << array1[2] << endl << array1[150] << endl;


	elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
	cout << elapsedTime << " ms.\n";
	

	return 0;
}


