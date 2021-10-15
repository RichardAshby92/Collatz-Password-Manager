#pragma once
#include <iostream>
#include <string>

class Accounts {
private:
	std::string m_username;
	std::string m_userpassword;
	int L = size(m_userpassword);
	int* P = new int[L];
	std::string userDetes{ "0" };
	
public:
	Accounts();
	~Accounts();
	void createAccount();
	void setUsername();
	void createPassword();
	void Encrypt(std::string a);
	void Print();
	void Store();
};


