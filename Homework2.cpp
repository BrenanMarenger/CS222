#include"AVL.h"
#include<iostream>
#include<assert.h>

using namespace std;

int main() {
	AVL treeLR;
	treeLR.insert(1, "one");
	treeLR.insert(2, "two");
	treeLR.insert(3, "three");
	treeLR.remove(3);
	assert(treeLR.isBalanced());
	assert(treeLR.isSorted());

	AVL treeRR;
	treeRR.insert(3, "three");
	treeRR.insert(2, "two");
	treeRR.insert(1, "one");
	treeRR.remove(2);
	assert(treeRR.isBalanced());
	assert(treeRR.isSorted());
	

	AVL treeLRR;
	treeLRR.insert(20, "a");
	treeLRR.insert(10, "b");
	treeLRR.insert(15, "c");
	treeLRR.insert(5, "d");
	treeLRR.insert(17, "e");
	treeLRR.insert(12, "f");
	treeLRR.remove(15);
	assert(treeLRR.isBalanced());
	assert(treeLRR.isSorted());

	AVL treeRLR;
	treeRLR.insert(50, "1");
	treeRLR.insert(60, "2");
	treeRLR.insert(55, "3");
	treeRLR.insert(40, "4");
	treeRLR.insert(65, "5");
	treeRLR.insert(52, "6");
	treeRLR.insert(57, "7");
	treeRLR.remove(65);
	assert(treeRLR.isBalanced());
	assert(treeRLR.isSorted());


	
	
	return 0;
}