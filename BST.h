#pragma once
#include <iostream>

using namespace std;

class BST {
protected:
	struct node
	{
		int value{ 0 };
		struct node* left = NULL;
		struct node* right = NULL;
	};
	struct node* root = NULL;
public:
	BST();
	~BST();
	void insert_integer(struct node** tree, int value);
	void print_tree(struct node* tree);
	void terminate_tree(struct node* tree);
};
