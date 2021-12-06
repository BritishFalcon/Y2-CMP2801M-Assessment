#include "Account.h"

Account::Account(long double startBalance)
{
	balance = startBalance;
}

void Account::deposit(long double depositAmount)
{
	balance += depositAmount;
}

void Account::withdraw(long double withdrawAmount)
{
	balance -= withdrawAmount;
}

string Account::toString()
{
	// Unfinished
}