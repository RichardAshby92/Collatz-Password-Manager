#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "BST.h"

class PasswordAnalysis : public BST{
private:
	struct node {
		virtual ~node()
		{
			delete right;
			right = nullptr;
			delete left;
			left = nullptr;
		}

		int value = 1;
		int level = 0;
		node* right = nullptr;;
		node* left = nullptr;;
	};
	node* tree = nullptr;
	std::vector<int> valuesAtDesiredHeight;
	int desiredHeight = 10;
	std::ifstream testFile{"passwordtest"};
	std::string encryptedLine;
public:
	PasswordAnalysis();
	~PasswordAnalysis();
	void runAnalysis();
	bool Checker(int x);
	node* newNode(int x, int i);
	void generateTree(node* tree, const int desiredHeight, std::vector<int>& valuesAtDesiredHeight);
	std::string getLine();
	void decryptLine();
};
