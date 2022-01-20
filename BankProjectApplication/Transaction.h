#pragma once

#ifndef TRANSACTION_H
#define TRANSACTION_H

#pragma warning(disable:4996)

#include "SourceFunctions.h"
#include <string>
#include <ctime>
#include <iostream>
#include <sstream>

class Transaction
{

public:

	std::string toString();

	Transaction(long double transactionAmount, std::string transactionDescription);

	long double getValue();

private:

	struct tm* timestamp;
	long double value;
	std::string desc;
};

#endif