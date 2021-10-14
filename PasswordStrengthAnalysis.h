#pragma once
#include <iostream>
#include <string>
#include "Accounts.h"

class PasswordStrengthAnalysis : public Accounts {
private:

public:
	PasswordStrengthAnalysis();
	~PasswordStrengthAnalysis();
	void GenerateFile();
	void ImportFile();
	void RunAnalysis();
};
