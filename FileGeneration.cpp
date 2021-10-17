#include <iostream>
#include <string>
#include <algorithm>
#include "FileGeneration.h"

FileGeneration::FileGeneration()
{

}

FileGeneration::~FileGeneration()
{
	//delete string array
}

void FileGeneration::generateFile()
{
	std::cout << "Generating File" << std::endl;
	generateArray();
	printFile();
	std::cout << "File Generated" << std::endl;
}

void FileGeneration::generateArray() {
	int n = 0;
	for (int i = 0; i < 10000; i++)
	{	
		if (i % 100 == 0)
		{	
			n++;
		}
		m_passArray[i] = gen_easy(n);
		m_passArrayEncrypt[i] = Encrypt(m_passArray[i], n);
		std::cout << m_passArrayEncrypt[i] << " ";
	}

	std::cout << "\n";
	
	n = 0;
	for (int i = 10000; i < 19500; i++)
	{
		if (i % 100 == 0)
		{
			n++;
		}
		m_passArray[i] = gen_hard(n);
		m_passArrayEncrypt[i] = Encrypt(m_passArray[i], n);
		//std::cout << m_passArrayEncrypt[i] << " ";
	}
}

std::string  FileGeneration::gen_easy(int len) {
	std::string s;

	const char possChar1[] = "abcdefghio";

	for (int i = 0; i < len; ++i) {
		s += possChar1[rand() % (sizeof(possChar1) - 1)];
	}

	return s;
}

std::string  FileGeneration::gen_hard(int len)
{
	std::string s;

	char possChar2[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz"
		"!#$%%&'()*+,-./:;<=>?@[]^_`{|}~';";

	for (int i = 94; i > 0; --i)
	{
		int j = rand() % i;
		int temp = possChar2[i];
		possChar2[i] = possChar2[j];
		possChar2[j] = temp;
	}

	for (int i = 1; i <= len; ++i) {
		s += possChar2[i];
	}
	return s;
}

std::string FileGeneration::Encrypt(std::string a, int x)
{
	int count = 0;
	int offset = 0;
	encryptValue.resize(x);
	m_passEncrypt = "";

	for (int i = 0; i < x; i++)
	{
		int n = a[i];

		for (n = n + offset; n != 1; count++)
		{
			n = (n % 2 == 0) ? n / 2 : 3 * n + 1;
		}

		encryptValue[i] = count;
		offset = count;
		count = 0;
	}

	for (int i = 0; i < x; i++)
	{
		m_passEncrypt = m_passEncrypt + std::to_string(encryptValue[i]);
	}
	return m_passEncrypt;
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

void FileGeneration::RunAnalysis()
{

}

