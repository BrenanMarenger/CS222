//Brenan Marenger
#include "BinaryTree.h"

template <typename T>
void BinaryTree<T>::buildRandom(int size, TreeNode*& ptr) {
	if (size == 0) {
		ptr = nullptr;
	}
	else {
		int d = rand() % 100;
		ptr = new TreeNode(d);
		int lsize = rand() % size;
		buildRandom(lsize, ptr->left);
		int rsize = size - lsize - 1;
		buildRandom(rsize, ptr->right);
	}
}

template <typename T>
void BinaryTree<T>::buildRandom(int size) {
	buildRandom(size, root_);
}

template <typename T>
void BinaryTree<T>::build(int size, TreeNode*& ptr) {
	if (size == 0) {
		ptr = nullptr;
	}
	else {
		T d;
		cout << "Give me a key." << endl;
		cin >> d;
		ptr = new TreeNode(d);
		int lsize = rand() % size;
		build(lsize, ptr->left);
		int rsize = size - lsize - 1;
		build(rsize, ptr->right);
	}
}

template <typename T>
void BinaryTree<T>::build(int size) {
	build(size, root_);
}

template <typename T>
void BinaryTree<T>::display() const {
	if (root_ == nullptr)
		cout << "-" << endl;
	else {
		displayLeft(root_->left, "  ");
		cout << root_->data << endl;
		displayRight(root_->right, "  ");
	}
}

template <typename T>
void BinaryTree<T>::displayLeft(TreeNode* subtree, string prefix) const
{
	if (subtree == nullptr)
	{
		cout << prefix + "/" << endl;
	}
	else
	{
		displayLeft(subtree->left, prefix + "     ");
		cout << prefix + "/---" << subtree->data << endl;
		displayRight(subtree->right, prefix + "|    ");
	}
}

template <typename T>
void BinaryTree<T>::displayRight(TreeNode* subtree, string prefix) const
{
	if (subtree == nullptr)
	{
		cout << prefix + "\\" << endl;
	}
	else
	{
		displayLeft(subtree->left, prefix + "|    ");
		cout << prefix + "\\---" << subtree->data << endl;
		displayRight(subtree->right, prefix + "     ");
	}
}

template <typename T>
int BinaryTree<T>::height(TreeNode* ptr) {
	if (ptr == nullptr)
		return -1;
	int lh = height(ptr->left);
	int rh = height(ptr->right);
	if (lh > rh)
		return 1 + lh;
	else
		return 1 + rh;
}

template<typename T>
int BinaryTree<T>::height() {
	return height(root_);
}

template <typename T>
void BinaryTree<T>::preorder(TreeNode* ptr) {
	if (ptr != nullptr) {
		cout << ptr->data << " ";
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

template <typename T>
void BinaryTree<T>::preorder() {
	preorder(root_);
}

template <typename T>
int BinaryTree<T>::size() {
	return rec_size(root_);
}

template <typename T>
int BinaryTree<T>::rec_size(TreeNode* ptr) {
	if (ptr == nullptr) {
		return 0;
	}
	return (rec_size(ptr->left) + rec_size(ptr->right)) + 1;
}

template<typename T>
int BinaryTree<T>::numberOfLeaves() {
	return rec_numberOfLeaves(root_);
}

template<typename T>
int BinaryTree<T>::rec_numberOfLeaves(TreeNode* ptr) {
	if (ptr == nullptr) {
		return 0;
	}

	if (ptr->left == nullptr && ptr->right == nullptr) {
		return 1;
	}
		return (rec_numberOfLeaves(ptr->left) + rec_numberOfLeaves(ptr->right));
}

template<typename T>
void BinaryTree<T>::leaves() {
	rec_leaves(root_);
}


template<typename T>
void BinaryTree<T>::rec_leaves(TreeNode* ptr) {
	if (ptr == nullptr) {
		return;
	}
	if (ptr->left == nullptr && ptr->right == nullptr) {
		cout << ptr->data << " ";
	}
	else {
		rec_leaves(ptr->left);
		rec_leaves(ptr->right);
	}
	
}

template<typename T>
void BinaryTree<T>::inorder() {
	rec_inorder(root_);
}

template<typename T>
void BinaryTree<T>::rec_inorder(TreeNode* ptr) {
	if (ptr != nullptr) {
		rec_inorder(ptr->left);
		cout << ptr->data << " ";
		rec_inorder(ptr->right);
	}
}

template<typename T>
void BinaryTree<T>::postorder() {
	rec_postorder(root_);
}

template<typename T>
void BinaryTree<T>::rec_postorder(TreeNode* ptr) {
	if (ptr != nullptr) {
		rec_postorder(ptr->left);
		rec_postorder(ptr->right);
		cout << ptr->data << " ";
	}
}

template<typename T>
T BinaryTree<T>::leftmost() {
	return rec_leftmost(root_);
}

template<typename T>
T BinaryTree<T>::rec_leftmost(TreeNode* ptr) {
	if (ptr->left != nullptr) {
		return rec_leftmost(ptr->left);
	}
	else {
		return ptr->data;
	}
}

template<typename T>
void BinaryTree<T>::rec_destr(TreeNode* ptr) {
	if (ptr) {
		rec_destr(ptr->left);
		rec_destr(ptr->right);
		delete ptr;
	}
}

template<typename T>
BinaryTree<T>::~BinaryTree() {
	rec_destr(root_);
}
