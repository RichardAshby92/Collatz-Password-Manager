#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "PasswordTool.h"

class FileGeneration : public PasswordTool {
private:
	std::string* m_passArray = new std::string[20000]; //remove
	std::string* m_passArrayEncrypt = new std::string[20000];
	std::fstream passwordTest; //remove
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
