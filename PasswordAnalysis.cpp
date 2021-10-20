#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "PasswordAnalysis.h"


PasswordAnalysis::PasswordAnalysis() {

}

PasswordAnalysis::~PasswordAnalysis() {

}

void PasswordAnalysis::runAnalysis() 
{
	std::cout << "Running Password Analysis" << std::endl;

	auto start = std::chrono::high_resolution_clock::now();
	getLine(); // get batch of 100 lines;

	for (int i = 0; i < 100; i++) {

		node* tree = newNode(1, 0);
		generateTree(tree, encryptLine[i]);
		decryptLine(encryptLine[i]);
	}

	std::cout << "Analysis complete" << std::endl;
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

	std::cout << "Average time taken to crack passwords: " << (duration.count())/100 << " microseconds" << std::endl;
	std::cout << "Percentage passwords cracked: " << passwordsCracked << std::endl;
}

bool PasswordAnalysis::Checker(int x) {
	if (x > 4 && (x - 4) % 6 == 0) {
		return true;
	}
	else {

		return false;
	}
}

PasswordAnalysis::node* PasswordAnalysis::newNode(int x, int i)
{
	node* N = new node;
	N->value = x;
	N->level = i;
	N->right = nullptr; 
	N->left = nullptr;  

	return N;
}

void PasswordAnalysis::generateTree(node* tree, const int desiredHeight)
{
	if (tree->level == desiredHeight)
	{
		if (tree->value < 255) {
			valuesAtDesiredHeight.push_back(tree->value);
			return;
		}
	}

	if (tree->value < 100000)
	{

		if (Checker(tree->value))
		{
			tree->left = newNode(((tree->value - 1) / 3), tree->level + 1);
			generateTree(tree->left, desiredHeight);

			tree->right = newNode((tree->value * 2), tree->level + 1);
			generateTree(tree->right, desiredHeight);
		}
		else
		{
			tree->left = newNode(((tree->value) * 2), tree->level + 1);
			generateTree(tree->left, desiredHeight);
		}

		return;
	}
}

void PasswordAnalysis::getLine()
{
	testFile.open("passwordtest.txt", std::ios::in);
	std::string s;
	for(int i = 0; i < 100; i++)
	{ 
		getline(testFile, s); 
		//Parse somehow
		int a = stoul(s);
		encryptLine.push_back(a);
	}
		testFile.close();	
}

void PasswordAnalysis::decryptLine(int x) {
	
		int n = 0;
		while (n < valuesAtDesiredHeight.size())
		{
			int Attempt = Encrypt(valuesAtDesiredHeight[n]);
			if (Attempt == x)
			{
				char out = char(valuesAtDesiredHeight[n]);
				std::cout << "password guessed" << std::endl;
				std::cout << out << std::endl;
				passwordsCracked++;

				break;
			}
			n++;
		}		
}

int PasswordAnalysis::Encrypt(int n)
{
	int count = 0;

		for (; n != 1; count++)
		{
			n = (n % 2 == 0) ? n / 2 : 3 * n + 1;
		}

	return count;
}