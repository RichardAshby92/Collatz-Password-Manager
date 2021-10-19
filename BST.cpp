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

void BST::insert_integer(struct node** tree, int x)
{
	while (level < 100)
	{
		if (*tree == NULL) //create new node
		{
			*tree = new node;
			(*tree)->value = x;
			(*tree)->left = NULL;
			(*tree)->right = NULL;
			level++;
		}

		std::cout << (*tree)->value << std::endl;
	
		if ((*tree)->value > 4 && (((*tree)->value) - 4) % 6 == 0)
		{
			insert_integer(&(*tree)->left, (x - 1) / 3);
		}

		else
		{				
			insert_integer(&(*tree)->right, 2 * x);
		}					
	}
}

void BST::print_tree(struct node* tree)
{
	if (tree->left != NULL)
	{
		print_tree(tree->left);
	}

	std::cout << (*tree).value << " ";

	if (tree->right != NULL)
	{
		print_tree(tree->right);
		std::cout << (*tree).value << " ";
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