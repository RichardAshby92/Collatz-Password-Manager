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
	void RunAnalysis();
	std::string gen_easy(int L);
	std::string gen_hard(int L);
	std::string Encrypt(std::string a, int x);

};
