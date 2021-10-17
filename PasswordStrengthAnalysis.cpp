#include <iostream>
#include <string>
#include <algorithm>
#include "PasswordStrengthAnalysis.h"

PasswordStrengthAnalysis::PasswordStrengthAnalysis() 
{

}

PasswordStrengthAnalysis::~PasswordStrengthAnalysis() 
{
	//delete string 
}

void PasswordStrengthAnalysis::generateFile()
{
	std::cout << "Generating File" << std::endl;
	generateArray();
	//Encrypt;
	printFile();

}

void PasswordStrengthAnalysis::generateArray() {

	for (int i = 0; i < 10000; i++)
	{	
		int n = 1;
		
		if (i % 100 == 0)
		{
			n++;
		}
		m_passArray[i] = gen_random(n);
	}

	std::cout << "\n";

	for (int i = 10000; i < 20000; i++)
	{
		int n = 1;

		if (i % 100 == 0)
		{
			n++;
		}
		m_passArray[i] = gen_random(n);
		std::cout << m_passArray[i];
	}
}

void PasswordStrengthAnalysis::printFile() 
{
	passwordTest.open("passwordTest.txt", std::ios::out);
	passwordTest << m_passArray[1][2] << "\n";
	passwordTest.close();
}

void PasswordStrengthAnalysis::RunAnalysis() {

}

std::string  PasswordStrengthAnalysis::gen_random(int len) {
	std::string s;
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < len; ++i) {
		s += alphanum[rand() % (sizeof(alphanum) - 1)];
	}

	return s;