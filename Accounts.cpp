#include <iostream>
#include <string>
#include "Accounts.h"

Accounts::Accounts(std::string user, std::string pass) : m_username{ user } {

}

Accounts::~Accounts()
{

}

int* Accounts::Encrypt(std::string a)
{
	{
		const int L = size(a);
		int count = 0;
		int offset = 0;
		int* P = new int[L];
		unsigned char n = a[0];


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

		m_userpassword = P;
		return P;
	}
}

int* Accounts::Store(std::string user, std::string pass)
{
	m_userDetes[i] = m_username + m_userpassword;
	i++;
}

void Accounts::Print(std::string user, std::string pass)
{
	const int L = size(pass);

	for (int i = 0; i < L; i++) {

		std::cout << P[i] << " ";
	}
}

void Accounts::ExportFile()
{

}
