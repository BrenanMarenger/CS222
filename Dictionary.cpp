#include "Dictionary.h"

Dictionary::TreeNode*& Dictionary::_find(int k, TreeNode*& ptr) {
	if (ptr == nullptr)
		return ptr;
	else if (k == ptr->key)
		return ptr;
	else if (k < ptr->key)
		return _find(k, ptr->left);
	else
		return _find(k, ptr->right);
}

string Dictionary::find(int k) {
	TreeNode* ptr = _find(k, root_);
	if (ptr == nullptr)
		return "Error: key not found!";
	else
		return ptr->data;
}

void Dictionary::insert(int k, string d) {
	TreeNode*& ptr = _find(k, root_);
	if (ptr != nullptr) {
		cout << "Error: insert() used an existing key!" << endl;
	}
	else {
		ptr = new TreeNode(k, d);
	}
}

void Dictionary::_inorder(TreeNode* ptr) {
	if (ptr != nullptr) {
		_inorder(ptr->left);
		cout << ptr->key << " : " << ptr->data << endl;
		_inorder(ptr->right);
	}
}

void Dictionary::inorder() {
	_inorder(root_);
	cout << endl;
}

Dictionary::TreeNode*& Dictionary::_rightmost(TreeNode*& ptr) {
	if (empty()) {
		return ptr;
	}
	if (ptr->right == nullptr) {
		return ptr;
	}
	else {
		return _rightmost(ptr->right);
	}
}

Dictionary::TreeNode*& Dictionary::_iop(TreeNode*& ptr) {
	if (empty()) {
		return ptr;
	}
	if (ptr->left != nullptr) {	
		return _rightmost(ptr->left);
	}
}

Dictionary::TreeNode*& Dictionary::_swapNodes(TreeNode*& ptr1, TreeNode*& ptr2) {
	int tempKey;
	string tempData;
	tempData = ptr1->data;
	tempKey = ptr1->key;
	ptr1->key = ptr2->key;
	ptr1->data = ptr2->data;
	ptr2->key = tempKey;
	ptr2->data = tempData;
	
	return ptr2;
}

string Dictionary::_remove(TreeNode*& ptr) {
	string temp = ptr->data;
	
	if (ptr->left == nullptr && ptr->right == nullptr) {
		delete ptr;
		ptr = nullptr;
	} else if (ptr->left != nullptr && ptr->right == nullptr) {
		TreeNode* tempPtr = ptr;
		ptr = ptr->left;
		delete tempPtr;
		ptr->left = nullptr;
	} else if (ptr->left == nullptr && ptr->right != nullptr) {
		TreeNode* tempPtr = ptr;
		ptr = ptr->right;
		delete tempPtr;
		ptr->right = nullptr;
	} else {
		TreeNode*& tempPtr = _iop(ptr);
		_swapNodes(ptr, tempPtr);
		return _remove(tempPtr);
	}
	return temp;
}

string Dictionary::remove(int k) {
	TreeNode*& ptr = _find(k, root_);
	return _remove(ptr);
}

void Dictionary::preorder() {
	return _preorder(root_);
}

void Dictionary::_preorder(TreeNode*& ptr) {
	if (ptr == nullptr) {
		return;
	}
		cout << ptr->key << " : " << ptr->data << endl;
		_preorder(ptr->left);
		_preorder(ptr->right);
}

void Dictionary::postorder() {
	return _postorder(root_);
}

void Dictionary::_postorder(TreeNode*& ptr) {
	if (ptr == nullptr) {
		return;
	}
	_postorder(ptr->left);
	_postorder(ptr->right);
	cout << ptr->key << " : " << ptr->data << endl;
}
