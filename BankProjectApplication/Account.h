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

	virtual void deposit(long double depositSum, std::string depositDescription);
	virtual void deposit(std::string depositSum, std::string depositDescription);
	//virtual void deposit(long double depositSum);
	//virtual void deposit(std::string depositSum);

	virtual void withdraw(long double withdrawSum, std::string withdrawDescription);
	virtual void withdraw(std::string withdrawSum, std::string withdrawDescription);
	//virtual void withdraw(long double withdrawSum);
	//virtual void withdraw(std::string withdrawSum);

	virtual std::string toString();
	virtual void toConsole();
	virtual std::string getType();


protected:

	Account(long double startBalance);

	long double balance; // Using long double to store currency with high accuracy to avoid rounding issues (particularly once applying interest)

	std::vector<Transaction> history;

	std::string type;

	virtual void generateTransaction(long double transactionSum, std::string transactionDescription);
};

#endif