#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "PasswordTool.h"

class FileGeneration : public PasswordTool {
private:
	std::string* passArrayEncrypted = new std::string[20000];
	int tempShuffleArr[100] = { 0 };

public:
	FileGeneration() {}
	virtual ~FileGeneration() {}

	virtual void Execute() override;

private:
	void generateFile();
	void generateArray();
	void printFile();
	int encrypt(int x);
};
