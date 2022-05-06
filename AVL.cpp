#include"AVL.h"


void AVL::_updateHeight(TreeNode*& curr) {
	if (curr == nullptr) {
		return;
	}
	if (curr->left == nullptr && curr->right == nullptr) { //if is a leaf
		curr->height = 0;
		return;
	}
	if (curr->right == nullptr && curr->left != nullptr) {  //has a left child
		curr->height = curr->left->height + 1;
		return;
	}
	if (curr->right != nullptr && curr->left == nullptr) {  //has a right child
		curr->height = curr->right->height + 1;
		return;
	}
	if (curr->right != nullptr && curr->left != nullptr) {
		if (curr->left->height > curr->right->height) { //has both, left child height is larger
			curr->height = curr->left->height + 1;
			return;
		}
		if (curr->left->height <= curr->right->height) { //has both, right is larger or equal to the left
			curr->height = curr->right->height + 1;
			return;
		}
	}
}

void AVL::_rotateLeft(TreeNode*& x) {
	if(x == NULL || x->right == NULL){
		return;
	} else {
		TreeNode* y = x->right;
		TreeNode* tmp = x;

		x->right = y->left;
		x = y->left;
		y = tmp;

		_updateHeight(x);
		_updateHeight(y);
	}
}

void AVL::_rotateRight(TreeNode*& x) {
	if (x == NULL || x->left == NULL) {
		return;
	}
	else {
		TreeNode* y = x->left;
		TreeNode* tmp = x;

		x->left = y->right;
		x = y->right;
		y = tmp;

		_updateHeight(x);
		_updateHeight(y);
	}
}

void AVL::_rotateRightLeft(TreeNode*& curr) {
	if (curr == nullptr) {
		return;
	}
	if (curr->height == NULL) {
		return;
	}
	TreeNode* temp = curr->right;
	_rotateLeft(temp);
	_updateHeight(curr);
	curr->right = temp;
	_rotateRight(curr);
	_updateHeight(curr);
}

void AVL::_rotateLeftRight(TreeNode*& curr) {
	if (curr == nullptr) {
		return;
	}
	if (curr->height == NULL) {
		return;
	}

	TreeNode* temp = curr->left;
	_rotateRight(temp);
	_updateHeight(curr);
	curr->left = temp;
	_rotateLeft(curr);

	_updateHeight(curr);
}

//Balancing
int AVL::heightBalance(TreeNode*& ptr) {
	int right;
	int left;
	if (ptr == nullptr) {
		return 0;
	}
	if (ptr->right == nullptr) {
		right = -1;
	}
	else {
		right = ptr->right->height;
	}
	if (ptr->left == nullptr) {
		left = -1;
	}
	else {
		left = ptr->left->height;
	}
	
	return right - left;
}

void AVL::_balance(TreeNode*& curr) {
	int  currHB;
	int leftHB;
	int rightHB;
	if (curr == nullptr) {
		return;
	}
	_updateHeight(curr);
	currHB = heightBalance(curr);
	
	if (currHB == 2) {
		leftHB = heightBalance(curr->left);
		rightHB = heightBalance(curr->right);
		if (leftHB == 1 || leftHB == 0) {
			//cout << "left rotation" << endl;
			_rotateLeft(curr);
			_updateHeight(curr);
			return;
		}
		if (leftHB == -1) {
			//cout << "right left rotaion" << endl;
			_rotateRightLeft(curr);
			_updateHeight(curr);
			return;
		}
	}
	if (currHB == -2) {
		leftHB = heightBalance(curr->left);
		rightHB = heightBalance(curr->right);
		if (rightHB == -1 || rightHB == 0) {
			//cout << "right rotation" << endl;
			_rotateRight(curr);
			_updateHeight(curr);
			return;
			
		}
		if (rightHB == 1) {
			//cout << "left right rotation" << endl;
			_rotateLeftRight(curr);
			_updateHeight(curr);
			return;
			
		}
	}
}

//insert
void AVL::insert(int k, string d) {
	_insert(k, d, root_);
}

void AVL::_insert(int k, string d, TreeNode*& ptr) {
	if (ptr == nullptr) {
		ptr = new TreeNode(k, d);
	}
	if (k == ptr->key) {
		return;
	}
	if (k > ptr->key) {
		_insert(k, d, ptr->right);
		_balance(ptr);
	}
	if (k < ptr->key) {
		_insert(k, d, ptr->left);
		_balance(ptr);
	}
	
}

//IOP
AVL::TreeNode*& AVL::_iop(TreeNode*& ptr) {
	if (ptr == nullptr){
		return ptr;
	}
	if (ptr->left != nullptr) {
		return _rightmost(ptr->left);
	}
}
AVL::TreeNode*& AVL::_rightmost(TreeNode*& ptr) {
	if (root_ == nullptr) {
		return ptr;
	}
	if (ptr->right == nullptr) {
		return ptr;
	}
	else {
		return _rightmost(ptr->right);
	}
}

//inOrder
void AVL::_inOrder(TreeNode*& ptr) {
	if (ptr != nullptr) {
		_inOrder(ptr->left);
		cout << ptr->key << " : " << ptr->data << endl;
		_inOrder(ptr->right);
	}
}
void AVL::inOrder() {
	_inOrder(root_);
	cout << endl;
}
//post
void AVL::postorder() {
	return _postorder(root_);
	cout << endl;
}

void AVL::_postorder(TreeNode*& ptr) {
	if (ptr != nullptr) {
		_postorder(ptr->left);
		_postorder(ptr->right);
		cout << ptr->key << " : " << ptr->data << endl;
	}
	
}
//pre
void AVL::preorder() {
	return _preorder(root_);
	cout << endl;
}

void AVL::_preorder(TreeNode*& ptr) {
	if (ptr != nullptr) {
		cout << ptr->key << " : " << ptr->data << endl;
		_preorder(ptr->left);
		_preorder(ptr->right);
	}
	
}

//remove
void AVL::remove(int k) {
	find_and_remove(k, root_);
}

void AVL::find_and_remove(int k, TreeNode*& ptr) {
	if (k == ptr->key) {
		_remove(ptr);
	}
	if (k > ptr->key) {
		find_and_remove(k, ptr->right);
	}
	if (k < ptr->key) {
		find_and_remove(k, ptr->left);
		
	}
	if (ptr == nullptr) {
		return;
	}
	_balance(ptr);
}

void AVL::_remove(TreeNode*& ptr) {
	string temp = ptr->data;

	if (ptr->left == nullptr && ptr->right == nullptr) { //no children
		delete ptr;
		ptr = nullptr;
	}
	if (ptr->left != nullptr && ptr->right == nullptr) { //right child
		TreeNode* tempPtr = ptr;
		ptr = ptr->right;
		delete ptr;
		ptr = nullptr;
	}
	else if (ptr->left == nullptr && ptr->right != nullptr) { //left child
		TreeNode* tempPtr = ptr;
		ptr = ptr->left;
		delete ptr;
		ptr = nullptr;
	}
	else { //two children
		TreeNode*& tempPtr = _iop(ptr);
		_swapNodes(ptr, tempPtr);
		_remove(tempPtr);
	}
}

//swap
AVL::TreeNode*& AVL::_swapNodes(TreeNode*& ptr1, TreeNode*& ptr2) {
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

//isBalanced
bool AVL::isBalanced() { //takes a pointer, recursive
	return _isBalanced(root_);
}

bool AVL::_isBalanced(TreeNode*& ptr) {
	bool lBal;
	bool rBal;
	if (heightBalance(ptr) >= 2 || heightBalance(ptr) <= -2) {
		return false;
	}

	if (ptr->left != nullptr) {
		rBal = _isBalanced(ptr->left);
	}
	if (ptr->right != nullptr) {
		lBal = _isBalanced(ptr->right);
	}
	
	return rBal && lBal;
}

//destructor
AVL::~AVL() { 
	rec_destr(root_);
}
void AVL::rec_destr(TreeNode*& ptr) {
	if (ptr) {
		rec_destr(ptr->left);
		rec_destr(ptr->right);
		delete ptr;
	}
}

//isSorted
bool AVL::isSorted() {
	return _isSorted(root_);
}

bool AVL::_isSorted(TreeNode*& ptr) { 

	if (ptr != nullptr) {
		return true;
	}
	if (ptr->left == nullptr && ptr->right == nullptr) { ///is a leaf
		return true;
	}
	if (ptr->left == nullptr && ptr->right != nullptr) {//has a right child
		if (ptr->key > ptr->right->key) {
			return false;
		}
		_isSorted(ptr->right);
	}
	if (ptr->left != nullptr && ptr->right == nullptr) {//has a left child
		if (ptr->key < ptr->left->key) {
			return false;
		}
		_isSorted(ptr->left);

	}
	if (ptr->left != nullptr && ptr->right != nullptr) { //has 2 children
		if (ptr->left->key > ptr->right->key) {
			return false;
		}
		_isSorted(ptr->left);
		_isSorted(ptr->right);
	}
	return true; 
}

