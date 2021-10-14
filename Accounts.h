#pragma once
#include <iostream>
#include <string>

class Accounts {
private:
	std::string m_username;
	std::string m_userpassword;
	std::string* m_userDetes = new std::string[];
	int static i;
public:
	Accounts();
	Accounts(std::string user, std::string pass);
	virtual ~Accounts();
	int* Encrypt(std::string a);
	int* Store(std::string user, std::string pass);
	void Print(std::string user, std::string pass);
	void ExportFile();
};


