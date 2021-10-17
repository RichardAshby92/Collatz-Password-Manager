#include <iostream>

#include "BST.h"

using namespace std;

BST::BST()
{

}

BST::~BST()
{
	/*if (root->left != NULL)
	{
		terminate_tree(root->left);
		delete root->left;
		root->left = NULL;
	}

	if (root->right != NULL)
	{
		terminate_tree(root->right);
		delete root->right;
		root->right = NULL;
	}

	root->value = NULL;*/
}

void BST::insert_integer(struct node** tree, int value)
{
	if (*tree == NULL)
	{
		*tree = new node;
		(*tree)->value = value;
		(*tree)->left = NULL;
		(*tree)->right = NULL;
	}

	else
	{
		if (value < (*tree)->value)
			insert_integer(&(*tree)->left, value);
		else
			insert_integer(&(*tree)->right, value);
	}
}

void BST::print_tree(struct node* tree)
{
	if (tree->left != NULL)
	{
		print_tree(tree->left);
	}

	if (tree->right != NULL)
	{
		print_tree(tree->right);
	}
}

void BST::terminate_tree(struct node* tree)
{
	if (tree->left != NULL)
	{
		terminate_tree(tree->left);
		delete tree->left;
		tree->left = NULL;
	}

	if (tree->right != NULL)
	{
		terminate_tree(tree->right);
		delete tree->right;
		tree->right = NULL;
	}
	tree->value = NULL;
}