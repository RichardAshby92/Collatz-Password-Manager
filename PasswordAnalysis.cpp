#include <iostream>
#include <fstream>
#include <string>
#include "PasswordAnalysis.h"

PasswordAnalysis::PasswordAnalysis() {

}

PasswordAnalysis::~PasswordAnalysis() {

}

void PasswordAnalysis::runAnalysis() 
{
	std::cout << "Running Password Analysis" << endl;
	std::cout << "Getting Test Passwords" << endl;

	node* tree = newNode(1, 0);	
	generateTree(tree, desiredHeight, valuesAtDesiredHeight);
	
	getLine();

	decryptLine();
	std::cout << "Analysis complete" << endl;
}

bool PasswordAnalysis::Checker(int x) {
	if (x > 4 && (x - 4) % 6 == 0) {
		return true;
	}
	else {
		return false;
	}
}

PasswordAnalysis::node* PasswordAnalysis::newNode(int x, int i)
{
	node* N = new node;
	N->value = x;
	N->level = i;
	N->right = nullptr; //Tip: DON'T USE NULL it is basically depricated and can lead to dodgy shinanigans
	N->left = nullptr;  // nullptr is the right value for an empty pointer

	return N;
}

void PasswordAnalysis::generateTree(node* tree, const int desiredHeight, std::vector<int>& valuesAtDesiredHeight)
{
	std::cout << tree->value << std::endl;
	//std::cout << tree->level << std::endl;

	if (tree->level == desiredHeight)
	{
		valuesAtDesiredHeight.push_back(tree->value);
		return; //Base case
	}

	if (Checker(tree->value))
	{
		tree->left = newNode(((tree->value - 1) / 3), tree->level + 1);
		generateTree(tree->left, desiredHeight, valuesAtDesiredHeight);

		tree->right = newNode((tree->value * 2), tree->level + 1);
		generateTree(tree->right, desiredHeight, valuesAtDesiredHeight);
	}
	else
	{
		tree->left = newNode(((tree->value) * 2), tree->level + 1);
		generateTree(tree->left, desiredHeight, valuesAtDesiredHeight);
	}

	return;

}

std::string PasswordAnalysis::getLine()
{
	testFile.open("passwordtest.txt", std::ios::in);
	std::string temp = getline(testFile, encryptedLine);

	testFile.close();
	return temp;
}

void PasswordAnalysis::decryptLine() {

}
