#include <iostream>
#include <string>
#include <algorithm>
#include "FileGeneration.h"


void FileGeneration::Execute()
{
	generateFile();
}

void FileGeneration::generateFile()
{
	std::cout << "Generating File" << std::endl;
	for (int i = 32; i < 132; i++)
	{
		tempShuffleArr[i - 32] = i;
	}
	generateArray();
	printFile();
	std::cout << "File Generated" << std::endl;
}

void FileGeneration::generateArray() {
	int n = 0;
	std::string s;
	int offset = 0;
	int temp = 0;
	int x = 0;

	for (int i = 0; i < 10000; i++)
	{
		if (i % 100 == 0)
		{
			n++;
		}
		x = n;
		s = "";

		while (x > 0) {
			temp = encrypt((rand() % 10 + 32) + offset); 
			if (n > 1) { offset = temp; }
			s += std::to_string(temp);
			x--;
		}
		
		passArrayEncrypted[i] = s;
	}

	n = 0;
	s = "";
	offset = 0;
	temp = 0;
	x = 0;

	for (int i = 10000; i < 20000; i++)
	{
		if (i % 100 == 0)
		{
			n++;
		}

		x = n;
		s = "";

		while (x > 0)
		{
			std::random_shuffle(std::begin(tempShuffleArr), std::end(tempShuffleArr));
			temp = encrypt((tempShuffleArr[0]) + offset);
			if (n > 1) { offset = temp; }
			s += std::to_string(temp);
			x--;
		}
		passArrayEncrypted[i] = s;
	}	
}

void FileGeneration::printFile()
{
	const std::string filePath("passwordTest.txt");
	WriteToFile(filePath, std::ios::out, [this](std::fstream& file)
	{
		for (int i = 0; i < 20000; i++)
		{
			file << passArrayEncrypted[i] << "\n";
		}
	});
}

int FileGeneration::encrypt(int n)
{
	int count = 0;

	for (; n != 1; count++)
	{
		n = (n % 2 == 0) ? n / 2 : 3 * n + 1;
	}

	return count;
}

