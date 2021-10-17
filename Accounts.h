#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Accounts {
private:
	std::fstream MyFile;
	std::string m_username;
	std::string m_userpassword;
	std::string m_passEncrypt;
	std::string userDetes{ "0" };
	std::vector<int> encryptValue;
	int L{ 0 };
	std::string passwordCompare;
	
public:
	Accounts();
	~Accounts();
	void createAccount();
	void setUsername();
	void createPassword();
	void Encrypt(std::string a);
	void Print();
	void Store();
	void signIn();
	bool readFile();
	bool passwordCheck();
};


