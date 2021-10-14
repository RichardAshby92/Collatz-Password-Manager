#include <iostream>
#include <string>
#include "Accounts.h"
#include "AccountManager.h"
#include "PasswordStrengthAnalysis.h"

using namespace std;

int main()
{
	AccountManager a1;
	//Menu and options
	cout << "Collatz Password Manager \nOptions: \nEnter 1 to create account \nEnter 2 to sign in \nEnter 3 to Create password strength anylsis file \nEnter 4 to Anaylsis a password strength file" << endl;

	//Main Loop
	int x = 0;
	int entries = 0;
	bool t = true;
	//int* userDetes = new int[L][];
	
	while (t) {
		std::cin >> x;
		switch (x) {
		case 1:
		{cout << "Creating an account \nEnter a Username: " << endl;
		string username = "0";
		string userpassword = "0";
		std::cin >> username;
		cout << "Enter a Password: " << endl;
		std::cin >> userpassword;
		Accounts a1(username, userpassword);
		a1.Store(username, userpassword);
		a1.Print(username, userpassword);
		t = false; }
			break;
		case 2:
			cout << "Sign in" << endl;
			t = false;
			break;
		case 3:
			cout << "Program 3" << endl;
			t = false;
			break;
		case 4:
			cout << "Program 4" << endl;
			t = false;
			break;
		default:
			cout << "Invalid Selection" << endl;
		}
	}


	return 0;
}

