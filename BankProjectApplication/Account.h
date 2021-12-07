#pragma once

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Transaction.h"

#include <string>
#include <ctime>
#include <iostream>

class Account
{

public:

	virtual void deposit(long double);
	virtual void deposit(std::string);

	virtual void withdraw(long double);
	virtual void withdraw(std::string);

	virtual std::string toString();


protected:

	Account(long double startBalance);

	long double balance; // Using long double to store currency with high accuracy to avoid rounding issues (particularly once applying interest)

};

#endif