#pragma once
#include <iostream>
#include <vector>
#include "BST.h"

class PasswordAnalysis : public BST{
private:
	std::vector<int> collatz;
public:
	PasswordAnalysis();
	~PasswordAnalysis();
	void runAnalysis();
	void getFile();
	void collatzValues();
	void generateBST();
	void decryptLine();
};
