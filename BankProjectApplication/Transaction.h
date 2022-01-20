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

	std::string toString(); // Represent the transaction in an easily readible way for output

	Transaction(long double transactionAmount, std::string transactionDescription); // Time is not required as input, as it will simply take current time

	long double getValue(); // Return value of transaction

private:
	// These are private as to avoid manipulation - they should never be changed once set (as they're a record of the past)
	std::string timestamp; // Stored as a string as there is no need to ever manipulate it, only read or print it
	long double value; // Double used for native compatibility with money in the rest of the program
	std::string desc; // Stored as string as, like timestamp, it only needs to be read and print
};

#endif