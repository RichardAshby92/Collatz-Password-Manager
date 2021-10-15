#include <iostream>
#include <string>
#include <fstream>
#include "Accounts.h"

Accounts::Accounts()
{

}

Accounts::~Accounts()
{
	delete[] P;
	
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
		const int L = size(m_userpassword);

		for (int i = 0; i < L; i++)
		{
			unsigned char n = a[i];

			for (n = n + offset; n != 1; count++)
			{
				n = (n % 2 == 0) ? n / 2 : 3 * n + 1;
			}

			P[i] = count;
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
		 temp = temp + std::to_string(P[i]);
	}

	userDetes = userDetes + " " + temp;
}

void Accounts::Store()
{
	std::ofstream MyFile("password.txt", std::ios::app);
	MyFile << userDetes << "\n";
	MyFile.close();
}



	
