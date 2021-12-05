#include <string>
#include <ctime>
#include <iostream>

class Account
{

public:

	void deposit();

	void withdraw();

	string toString();


protected:

	Account(long double startBalance);

	long double balance;

};


class Transaction
{

public:

	string toString();

	Transaction(long double transValue, tm transTimestamp, string transDescription);

};


class InterestEarning
{

protected:

	InterestEarning(long double newInterestRate);
	long double interestRate;

};

class Current : public Account
{

public:

	Current(long double startBalance);

};

class Savings : public Account, public InterestEarning
{

public:

	Savings(bool isISA, long double startBalance);

};