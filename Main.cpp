#include <iostream>
#include <string>
#include "Accounts.h"
#include "FileGeneration.h"
#include "PasswordAnalysis.h"

int main()
{
	Accounts accounts;
	FileGeneration fileGeneration;
	PasswordAnalysis passwordAnalysis;

	int x;
	bool t = true;

	std::cout << "Collatz Password Manager \nOptions: \nEnter 1 to create account \nEnter 2 to sign in \n";
	std::cout << "Enter 3 to generate a password strength anylsis file \nEnter 4 to Anaylsis a password strength file \n";
	std::cout << "Enter 0 to exit the program" << std::endl;
	
	while (t) {
		//Menu and options
		std::cin >> x;
		if (!std::cin.good()) {
			std::cout << "Invalid Selection" << std::endl;
			break;
		}
		switch (x) {
		case 0:
			t = false;
			break;
		case 1:
			accounts.createAccount();
			break;
		case 2:
			accounts.Execute();
			break;
		case 3:
			fileGeneration.Execute();
			break;
		case 4:
			passwordAnalysis.Execute();
			break;
		default:
			std::cout << "Invalid Selection" << std::endl;
			break;
		}
		
		std::cout << "Returned to menu\n";
	}
	return 0;
}


