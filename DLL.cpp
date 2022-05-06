#include "DLL.h"
#include"assert.h"

int main() {
	DLL<int> l1;
	assert(l1.empty() == true);
	l1.pushFront(3);
	assert(l1.empty() == false);
	l1.popFront();
	assert(l1.empty() == true);

	l1.pushFront(34);
	l1.pushFront(5);
	l1.pushFront(11);
	assert(l1.rec_size() == 3);

	assert(l1.rec_find(5)== true);
	assert(l1.rec_find(12) == false);
	assert(l1.rec_find(34) == true);

	l1.popFront();
	assert(l1.rec_size() == 2);
	l1.popFront();
	assert(l1.rec_size() == 1);

	l1.pushBack(45);
	assert(l1[1] == 45);
	l1.pushBack(23);
	assert(l1[2] == 23);
	l1.pushBack(2);
	assert(l1.rec_size() == 4);
	
	l1.popBack();
	assert(l1.rec_size() == 3);
	l1.popBack();
	assert(l1.rec_find(23) == false);
	l1.popBack();
	assert(l1[0]==34);

	return 0;
}