#pragma once
#include <iostream>
#include <string>
#include "Accounts.h"

class AccountManager : public Accounts {
private:
	int retries;
public: 
	AccountManager();
	virtual ~AccountManager();
	bool AccountMatch();
};
