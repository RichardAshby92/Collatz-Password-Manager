#pragma once
#include <iostream>
#include <string>
#include "Accounts.h"

class AccountManager : public Accounts {
private:
	int m_retries;
public: 
	AccountManager();
	virtual ~AccountManager();
	bool AccountMatch();
};
