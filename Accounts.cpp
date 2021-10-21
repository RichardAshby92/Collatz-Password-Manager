#include <iostream>
#include <string>
#include <sstream>
#include<cstdlib>
#include "Accounts.h"

void Accounts::Execute()
{
	signIn();
}

void Accounts::createAccount()
{
	std::cout << "Creating an account \nEnter a Username: " << std::endl;
	setUsername();
	std::cout << "Enter a Password" << std::endl;
	createPassword();
	Encrypt(m_userpassword);
	Print();
	Store();
}

void Accounts::setUsername()
{
	std::cin >> m_username;
	userDetes = m_username;
}

void Accounts::createPassword() 
{
	std::cin >> m_userpassword;
	L = size(m_userpassword);
}

void Accounts::Encrypt(std::string a)
{
	int count = 0;
	int offset = 0;
	m_passEncrypt = "";
	int n = a[0];
	L = a.size();
	encryptValue.resize(L);

	for (int i = 0; i < L; i++)
	{
		n = a[i];

		for (n = n + offset; n != 1; count++)
		{
				n = (n % 2 == 0) ? n / 2 : 3 * n + 1;
		}

		encryptValue[i] = count;
		offset = count;
		count = 0;
	}

	for (auto value : encryptValue)
	{
		m_passEncrypt += std::to_string(value);
	}
	
	userDetes = userDetes + " " + m_passEncrypt;
}

void Accounts::Print()
{
	for (auto value : encryptValue)
	{
		m_passEncrypt += std::to_string(value);
	}
}

void Accounts::Store() //uses passwordTool template and llambda function
{
	std::string filePath("password.txt");
	WriteToFile(filePath, std::ios::app, [this](std::fstream& file)
	{
		file << userDetes << "\n";
	});
}

void Accounts::signIn()
{
	std::cout << "Sign in \n Enter a Username : " << std::endl;
	std::cin >> m_username;
	int passAttempts = 3;
	try { if (readFile()); 
		else return;
		}
	catch (const char* fileMissing) {
		std::cout << fileMissing;
		return;
	}

	while (passAttempts > 0)
	{
		if (passwordCheck())
		{
			std::cout << "Sign in Successfull" << std::endl;
			return;
		}
		else
		{
			std::cout << "Password Incorrect" << std::endl;
			passAttempts--;
			std::cout << "Attempts Remaining: " << passAttempts << std::endl;
		}
	}
}

bool Accounts::readFile() throw ()
{	
	std::fstream file("password.txt", std::ios::in);
	if (file.fail()) {
		throw "Missing File \n";
	}

	while (getline(file, passwordCompare)) {
		if (passwordCompare.find(m_username) != std::string::npos)
		{
			file.close();
			return true;
		}
	}
	std::cout << "Username not found" << std::endl;
	file.close();
	return false;	
}

bool Accounts::passwordCheck() 
{
	std::cout << "Enter Password: " << std::endl;
	std::cin >> m_userpassword;
	Encrypt(m_userpassword);
	std::istringstream iss(passwordCompare);
	std::string password;
	char delim = ' ';
	std::getline(iss, password, delim);
	std::getline(iss, password, delim);

	return password == m_passEncrypt;	
}
