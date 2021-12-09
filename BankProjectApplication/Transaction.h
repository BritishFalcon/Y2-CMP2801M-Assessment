#pragma once

#ifndef TRANSACTION_H
#define TRANSACTION_H

#pragma warning(disable:4996)

#include <string>
#include <ctime>
#include <iostream>

class Transaction
{

public:

	std::string toString();

	Transaction(long double transactionAmount, std::string transactionDescription);

private:

	struct tm* timestamp;
	long double value;
	std::string desc;
};

#endif