#include <iostream>
#include "PasswordAnalysis.h"

PasswordAnalysis::PasswordAnalysis() {

}

PasswordAnalysis::~PasswordAnalysis() {

}

void PasswordAnalysis::runAnalysis() 
{
	std::cout << "Running Password Analysis" << endl;
	getFile();
	collatzValues();
	generateBST();
	decryptLine();
	std::cout << "Analysis complete" << endl;
}

void PasswordAnalysis::getFile() 
{
	std::cout << "Getting Test Passwords" << endl;
}

void PasswordAnalysis::collatzValues()
{
	collatz[0] = { 1 };

	for (int i = 0; i < 100; i++)
	{
		if ((i - 4) % 4) 
		{
			collatz[i] = (i - 1) / 3;
		}
		collatz[i] = 2 * i;
	}
}

void PasswordAnalysis::generateBST() 
{
	std::cout << "Generating BST" << endl;
	
	

}

void PasswordAnalysis::decryptLine() {

}
