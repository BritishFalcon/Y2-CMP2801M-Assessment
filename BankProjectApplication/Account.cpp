#include "Account.h"

Account::Account(long double startBalance)
{
	balance = startBalance;
}

void Account::deposit(long double depositAmount)
{
	balance += depositAmount;
}

void Account::deposit(std::string depositAmount)
{
	balance += std::stold(depositAmount);
}

void Account::withdraw(long double withdrawAmount)
{
	balance -= withdrawAmount;
}

void Account::withdraw(std::string withdrawAmount)
{
	balance -= std::stold(withdrawAmount);
}


std::string Account::toString()
{
	// Unfinished
	return "PLACEHOLDER";
}