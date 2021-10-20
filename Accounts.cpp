#include <iostream>
#include <string>
#include <fstream>
#include<cstdlib>
#include "Accounts.h"

Accounts::Accounts()
{

}

Accounts::~Accounts()
{

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
	//check for existing username
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
		int n = a[0];
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

		for (int i = 0; i < L; i++)
		{
			m_passEncrypt = m_passEncrypt + std::to_string(encryptValue[i]);
		}
		userDetes = userDetes + " " + m_passEncrypt;
		m_passEncrypt = "";
}

void Accounts::Print()
{
	for (int i = 0; i < L; i++) 
	{ 
		m_passEncrypt = m_passEncrypt + std::to_string(encryptValue[i]);
	}
}

void Accounts::Store()
{
	MyFile.open("password.txt", std::ios::app);
	MyFile << userDetes << "\n";
	MyFile.close();
}

void Accounts::signIn()
{
	std::cout << "Sign in \n Enter a Username : " << std::endl;
	std::cin >> m_username;
	int passAttempts = 3;
	if (readFile());
	else return;
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

bool Accounts::readFile()
{
	//missing file exc eption here
	 MyFile.open("password.txt", std::ios::in);
	 while (getline(MyFile, passwordCompare)) {
		 if (passwordCompare.find(m_username) != std::string::npos)
		 { 
			 MyFile.close();
			 return true;
		 }
	 }
	 std::cout << "Username not found";
	 MyFile.close();
	 return false;
}

bool Accounts::passwordCheck() 
{
	std::cout << "Enter Password: " << std::endl;
	std::cin >> m_userpassword;
	Encrypt(m_userpassword);
	if (passwordCompare.find(m_passEncrypt) != std::string::npos)
	{
		return true;
	}
	else { return false; }
}
