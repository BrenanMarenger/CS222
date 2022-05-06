#include "Dictionary.h"

int main() {

	cout << endl << "---EXAMPLE 1---" << endl;
	Dictionary d;
	if (d.empty())
		cout << "The dictionry is empty!" << endl;
	cout << d.find(1) << endl;
	d.insert(3, "John");
	d.insert(2, "Emily");
	d.insert(4, "Bob");
	d.insert(0, "Alice");
	d.insert(1, "Eve");
	cout << d.find(1) << endl;
	cout << "Inorder: " << endl;
	d.inorder();
	cout << "Preorder: " << endl;
	d.preorder();
	d.remove(2);
	cout << "Postorder: (removed 2) " << endl;
	d.postorder();

	cout << endl << "---EXAMPLE 2---" << endl;
	Dictionary c;
	if (c.empty())
		cout << "The dictionry is empty!" << endl;
	c.insert(5, "Five");
	c.insert(6, "Six");
	c.insert(3, "Three");
	c.insert(10, "Ten");
	c.insert(7, "Seven");
	c.insert(4, "Four");
	c.insert(2, "Two");
	cout << c.find(3) << endl;
	cout << "Inorder: " << endl;
	c.inorder();
	c.remove(7);
	cout << "Preorder: (removed 7) " << endl;
	c.preorder();
	cout << "Postorder: " << endl;
	c.postorder();

	cout << endl << "---EXAMPLE 3---" << endl;
	Dictionary b;
	if (b.empty())
		cout << "The dictionry is empty!" << endl;
	b.insert(40, "Banana");//no left subtree
	b.insert(55, "apple");
	b.insert(50, "grape");
	b.insert(60, "kiwi");
	b.insert(52, "raspberry");
	b.insert(65, "mango");
	cout << "Inorder: " << endl;
	b.inorder();
	cout << "Preorder: " << endl;
	b.preorder();
	b.remove(65);
	cout << "Postorder: (removed 65) " << endl;
	b.postorder();

	return 0;
}