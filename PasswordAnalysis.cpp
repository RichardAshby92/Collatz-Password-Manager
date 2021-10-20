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
	std::cout << "Running Password Analysis" << std::endl;
	//std::cout << "Getting Test Passwords" << std::endl;

	getLine();
	std::cout << encryptedLine << std::endl;
	//int a = std::stoi(encryptedLine);
	int a = 25;
	std::cout << a << std::endl;

	node* tree = newNode(1, 0);	
	generateTree(tree, a, valuesAtDesiredHeight);

	decryptLine(encryptedLine);
	std::cout << "Analysis complete" << std::endl;
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
	N->right = nullptr; 
	N->left = nullptr;  

	return N;
}

void PasswordAnalysis::generateTree(node* tree, const int desiredHeight, std::vector<int>& valuesAtDesiredHeight)
{
	//std::cout << tree->value << std::endl;
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
	getline(testFile, encryptedLine);

	testFile.close();
	return encryptedLine;
}

void PasswordAnalysis::decryptLine(std::string encryptedLine) {
	int a = std::stoi(encryptedLine);
	//pasrse line

	int i = 0;
	while (1)
	{
		int Attempt = Encrypt(valuesAtDesiredHeight[i]);
		if (Attempt == a)
		{
			std::cout << "password guessed" << std::endl;
			break;
		}

		i++;
	}

}

int PasswordAnalysis::Encrypt( int n)
{
	int count = 0;

		for (; n != 1; count++)
		{
			n = (n % 2 == 0) ? n / 2 : 3 * n + 1;
		}

	return count;
}