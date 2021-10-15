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
	userDetes = m_username;
}

void Accounts::createPassword() 
{

	std::cin >> m_userpassword;
	L = size(m_userpassword);

}

void Accounts::Encrypt(std::string a)
{
	{
		int count = 0;
		int offset = 0;
		unsigned char n = a[0];
		L = size(m_userpassword);
		encryptValue.resize(L);

		for (int i = 0; i < L; i++)
		{
			unsigned char n = a[i];

			for (n = n + offset; n != 1; count++)
			{
				n = (n % 2 == 0) ? n / 2 : 3 * n + 1;
			}

			encryptValue[i] = count;
			offset = count;
			count = 0;
		}
	}
}

void Accounts::Print()
{

	std::string temp;

	for (int i = 0; i < L; i++) 
	{
		 temp = temp + std::to_string(encryptValue[i]);
	}

	userDetes = userDetes + " " + temp;
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
	if (readFile()) {
		if (passwordCheck) {
			std::cout << "Succesfully Signed in" << std::endl;
		}
	}
	else return;

}

bool Accounts::readFile()
{
	std::string text;

	 MyFile.open("password.txt", std::ios::in);
	 while (getline(MyFile, text)) {
		 if (text.find(m_username) != std::string::npos)
			 std::cout << "Username Found";
		 else { std::cout << "Username not found"; 
			return false;
				}
	 }

	 MyFile.close();
	 return true;
}

bool Accounts::passwordCheck() {
	std::cout << "Enter Password: " << std::endl;
	std::cin >> m_userpassword;
	if (text.find(m_username) != std::string::npos)
		std::cout << "Username Found";
	else {
		std::cout << "Username not found";
		return false;
	}

}
