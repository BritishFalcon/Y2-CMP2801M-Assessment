#pragma once

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Transaction.h"

#include <string>
#include <ctime>
#include <iostream>
#include <vector>
#include <sstream>

class Account
{

public:
	// All pure virtual functions
	virtual void deposit(long double depositSum, std::string depositDescription);
	virtual void deposit(std::string depositSum, std::string depositDescription); // Allow automatic conversion to long double

	virtual void withdraw(long double withdrawSum, std::string withdrawDescription);
	virtual void withdraw(std::string withdrawSum, std::string withdrawDescription); // Allow automatic conversion to long double

	virtual std::string toString();
	virtual void toConsole(); // For printing all account information; used a number of times
	virtual const std::string getType();
	virtual const long double& getBalance();
	virtual const long double& getMinBalance();
	virtual std::vector<Transaction> searchTransaction(long double searchParameter); // Used for search

protected:

	Account(long double startBalance);

	long double balance; // Using long double to store currency with high accuracy to avoid rounding issues (particularly once applying interest)

	std::vector<Transaction> history;

	std::string type;

	long double minBalance = 0;

	virtual void generateTransaction(long double transactionSum, std::string transactionDescription);

	// Nothing here is private as this is purely a base class
};

#endif