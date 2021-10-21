#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "PasswordTool.h"

class Accounts : public PasswordTool {
protected:
	std::string username{ "" };
	std::string userpassword{ "" };
	std::string passEncrypt{ "" };
	std::string userDetes{ "0" };
	int L{ 0 };
	std::string passwordCompare{ "" };
	std::vector<int> encryptValue{ 0 };
	
public:
	Accounts() {};
	~Accounts() {};
	virtual void Execute() override;
	void createAccount();

private:
	void setUsername();
	void createPassword();
	void Encrypt(std::string a);
	void Store();
	void signIn();
	bool readFile();
	bool passwordCheck();
};


