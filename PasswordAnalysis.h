#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "PasswordTool.h"

struct node {

	node()
		: value(1)
		, level(0)
		, right()
		, left()
	{}

	node(int inValue, int inLevel)
		: value(inValue)
		, level(inLevel)
		, right()
		, left()
	{}

	int value;
	int level;
	std::unique_ptr<node> right;
	std::unique_ptr<node> left;
};

class PasswordAnalysis : public PasswordTool {
private:	
	std::vector<int> valuesAtDesiredHeight{ 0 };
	int desiredHeight{1};
	std::ifstream testFile{ "passwordtest" };
	std::vector<int> encryptLine{ 0 };
	int passwordsCracked{ 0 };

public:
	PasswordAnalysis() {};
	~PasswordAnalysis() {};
	virtual void Execute() override;

private:
	void runAnalysis();
	bool Checker(int x);
	void generateTree(node& tree, const int desiredHeight);
	void getLine();
	void decryptLine(int x);
	int Encrypt(int x);
};
