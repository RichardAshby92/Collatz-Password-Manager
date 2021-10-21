#include <iostream>
#include <string>
#include "Accounts.h"
#include "FileGeneration.h"
#include "PasswordAnalysis.h"

int main()
{
	Accounts a1;
	FileGeneration p1;
	PasswordAnalysis x1;

	int x;
	bool t = true;

	std::cout << "Collatz Password Manager \nOptions: \nEnter 1 to create account \nEnter 2 to sign in \n";
	std::cout << "Enter 3 to generate a password strength anylsis file \nEnter 4 to Anaylsis a password strength file \n";
	std::cout << "Enter 5 to exit the program" << std::endl;
	
	while (t) {
		//Menu and options
	std::cin >> x;
		switch (x) {
		case 0:
			std::cout << "Invalid Selection" << std::endl;;
			break;
		case 1:
			a1.createAccount();
			break;
		case 2:
			a1.Execute();
			break;
		case 3:
			p1.Execute();
			break;
		case 4:
			x1.Execute();
			break;
		case 5:
			t = false;
			break;
		default:
			std::cout << "Invalid Selection" << std::endl;
			break;
		}
		
		std::cout << "Returned to menu\n";
	}
	return 0;
}


