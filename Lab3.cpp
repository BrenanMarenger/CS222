//Brenan Marenger
#include "BinaryTree.h"

int main() {
	srand(time(NULL));

	BinaryTree<int> t1;
	t1.buildRandom(7);
	t1.display();
	cout << "Size: " << t1.size() << endl;
	cout << "Number of Leaves: " << t1.numberOfLeaves() << endl;
	cout << "Leaves : ";
	t1.leaves();
	cout << endl << "Inorder : ";
	t1.inorder();
	cout << endl << "Preorder: ";
	t1.preorder();
	cout << endl << "Postorder: ";
	t1.postorder();
	cout << endl << "Leftmost: " << t1.leftmost() << endl;


	cout << endl;
	BinaryTree<char> t2;
	t2.build(5);
	t2.display();
	cout << "Size: " << t2.size() << endl;
	cout << "Number of Leaves: " << t2.numberOfLeaves() << endl;
	cout << "Leaves : ";
	t2.leaves();
	cout << endl << "Inorder : ";
	t2.inorder();
	cout << endl << "Preorder: ";
	t2.preorder();
	cout << endl << "Postorder: ";
	t2.postorder();
	cout << endl << "Leftmost: " <<t2.leftmost() << endl;
	
	BinaryTree<int> t3;
	t3.build(6);
	t3.display();
	cout << "Size: " << t3.size() << endl;
	cout << "Number of Leaves: " << t3.numberOfLeaves() << endl;
	cout << "Leaves : ";
	t3.leaves();
	cout << endl << "Inorder : ";
	t3.inorder();
	cout << endl << "Preorder: ";
	t3.preorder();
	cout << endl << "Postorder: ";
	t3.postorder();
	cout << endl << "Leftmost: " << t3.leftmost() << endl;

	return 0;
}