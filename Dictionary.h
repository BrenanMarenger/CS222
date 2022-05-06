#pragma once
#include <iostream>
#include <string>

using namespace std;
// template <typename K, typename D>
class Dictionary {
public:
	Dictionary(): root_(nullptr) {}
	bool empty() const { return !root_; }
	string find(int k);
	void insert(int k, string d);
	void inorder();
	string remove(int k);
	void preorder();
	void postorder();
	
private:
	class TreeNode {
	public:
		int key;
		string data;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int k, string d): key(k), data(d), left(nullptr), right(nullptr) {}
	};
	TreeNode* root_;
	TreeNode*& _find(int k, TreeNode*& ptr);
	void _inorder(TreeNode*);
	TreeNode*& _rightmost(TreeNode*& ptr);
	TreeNode*& _iop(TreeNode*& ptr);
	TreeNode*& _swapNodes(TreeNode*& ptr1, TreeNode*& ptr2);
	string _remove(TreeNode*& ptr);
	void _preorder(TreeNode*& ptr);
	void _postorder(TreeNode*& ptr);
};
