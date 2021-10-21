#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "PasswordAnalysis.h"

void PasswordAnalysis::Execute()
{
	runAnalysis();
}

void PasswordAnalysis::runAnalysis() 
{//Looped for each batch of 100
	std::cout << "Running Password Analysis" << std::endl;
	passwordsCracked = 0;
	auto start = std::chrono::high_resolution_clock::now();
	getLine(); // get batch of 100 lines;

	for (int i = 0; i < 100; i++) {

		std::unique_ptr<node> tree = std::make_unique<node>();
		generateTree(*tree.get(), encryptLine[i]);
		decryptLine(encryptLine[i]);
	}

	std::cout << "Analysis complete" << std::endl;
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

	std::cout << "Average time taken to crack passwords: " << (duration.count())/100 << " microseconds" << std::endl;
	std::cout << "Percentage passwords cracked: " << passwordsCracked << std::endl;
}

bool PasswordAnalysis::Checker(int x) {
	return (x > 4 && (x - 4) % 6 == 0);
}

void PasswordAnalysis::generateTree(node& tree, const int desiredHeight)
{
	if (tree.level == desiredHeight)
	{
		if (tree.value < 255) {
			valuesAtDesiredHeight.push_back(tree.value);
			return;
		}
	}

	if (tree.value < 100000)
	{
		if (Checker(tree.value))
		{
			tree.left = std::make_unique<node>(((tree.value - 1) / 3), tree.level + 1);
			generateTree(*tree.left.get(), desiredHeight);

			tree.right = std::make_unique<node>((tree.value * 2), tree.level + 1);
			generateTree(*tree.right.get(), desiredHeight);
		}
		else
		{
			tree.left = std::make_unique<node>(((tree.value) * 2), tree.level + 1);
			generateTree(*tree.left.get(), desiredHeight);
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
	
	for(auto value : valuesAtDesiredHeight)
	{
		int Attempt = Encrypt(value);
		if (Attempt == x)
		{
			char out = char(value);
			std::cout << "password guessed" << std::endl;
			std::cout << out << std::endl;
			passwordsCracked++;

			break;
		}
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