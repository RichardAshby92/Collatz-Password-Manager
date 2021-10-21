#include <iostream>
#include <string>
#include <algorithm>
#include "FileGeneration.h"

void FileGeneration::generateFile()
{
	std::cout << "Generating File" << std::endl;
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
			temp = encrypt((rand() % 10 + 97) + offset); //missing unique generation
			offset = temp;
			s += std::to_string(temp);
			x--;
		}
		
		m_passArrayEncrypt[i] = s;
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
			srand(i);
			temp = (encrypt(rand() % 100 + 97) + offset);
			offset = temp;
			s += std::to_string(temp);
			x--;
		}

		m_passArrayEncrypt[i] = s;
	}	
}

void FileGeneration::printFile()
{
	passwordTest.open("passwordTest.txt", std::ios::out);
	for (int i = 0; i < 20000; i++)
	{
		passwordTest << m_passArrayEncrypt[i] << "\n";
	}
	passwordTest.close();
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

