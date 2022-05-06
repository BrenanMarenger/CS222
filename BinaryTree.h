//Brenan Marenger
#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class BinaryTree {
public:
	BinaryTree() : root_(nullptr) {}
	void buildRandom(int size);
	void build(int size);
	void display() const;
	int height();
	void preorder();
	int size();
	int numberOfLeaves();
	void leaves();
	void inorder();
	void postorder();
	T leftmost();
	~BinaryTree();
	
private:
	class TreeNode {
	public:
		T data;
		TreeNode* left;
		TreeNode* right;
		TreeNode(T d) : data(d), left(nullptr), right(nullptr) {}
	};
	TreeNode* root_;
	void buildRandom(int, TreeNode*&);
	void build(int, TreeNode*&);
	void displayRight(TreeNode*, string) const;
	void displayLeft(TreeNode*, string) const;
	int height(TreeNode*);
	void preorder(TreeNode*);
	int rec_size(TreeNode*);
	int rec_numberOfLeaves(TreeNode*);
	void rec_leaves(TreeNode*);
	void rec_inorder(TreeNode*);
	void rec_postorder(TreeNode*);
	T rec_leftmost(TreeNode*);
	void rec_destr(TreeNode*);
};

#include "BinaryTree.hpp"
