#pragma once
#include <iostream>
#include <string>
#include "Accounts.h"

class PasswordStrengthAnalysis : public Accounts {
private:
	//std::string m_passArray[20][100];
	std::string* m_passArray = new std::string[20000];
	std::fstream passwordTest;
public:
	PasswordStrengthAnalysis();
	virtual ~PasswordStrengthAnalysis();
	void generateFile();
	void generateArray();
	void printFile();
	void RunAnalysis();
	std::string gen_random(int L);
};
