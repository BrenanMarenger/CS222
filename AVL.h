#pragma once
#include <iostream>
#include <string>

using namespace std;

class AVL {
public:
	AVL() : root_(nullptr) {}
	void insert(int k, string d);
	
	void inOrder();
	void postorder();
	void preorder();
	void remove(int k);
	
	bool isBalanced();
	bool isSorted();
	~AVL();
	
	

private:
	class TreeNode {
	public:
		int key;
		string data;
		TreeNode* left;
		TreeNode* right;
		int height;
		TreeNode(int k, string d) : key(k), data(d), left(nullptr), right(nullptr), height(0) {}
	};
	TreeNode* root_;

	void _insert(int k, string d, TreeNode*& root_);
	TreeNode*& _iop(TreeNode*& ptr);
	TreeNode*& _rightmost(TreeNode*& ptr);
	void _inOrder(TreeNode*& ptr);
	void _postorder(TreeNode*& ptr);
	void _preorder(TreeNode*& ptr);
	void _remove(TreeNode*& ptr);
	TreeNode*& _swapNodes(TreeNode*& ptr1, TreeNode*& ptr2);
	void _updateHeight(TreeNode*& curr);
	void find_and_remove(int k, TreeNode*& ptr);
	
	
	void _rotateLeft(TreeNode*& curr);
	void _rotateRight(TreeNode*& curr);
	void _rotateRightLeft(TreeNode*& curr);
	void _rotateLeftRight(TreeNode*& curr);
	void _balance(TreeNode*& curr);
	
	int heightBalance(TreeNode*& ptr);
	
	void rec_destr(TreeNode*&);
	bool _isSorted(TreeNode*&);
	bool _isBalanced(TreeNode*&);
	
};