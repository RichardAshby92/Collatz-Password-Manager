#pragma once
#include <iostream>
#include <string>
#include "Accounts.h"

class FileGeneration : public Accounts {
private:
	std::string* m_passArray = new std::string[20000];
	std::string* m_passArrayEncrypt = new std::string[20000];
	std::fstream passwordTest;
public:
	FileGeneration();
	virtual ~FileGeneration();
	void generateFile();
	void generateArray();
	void printFile();
	int encrypt(int x);

};
