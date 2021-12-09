#include "Account.h"

Account::Account(long double startBalance)
{
	balance = startBalance;

	Transaction newTransaction(startBalance, "initial deposit");
	history.push_back(newTransaction);
}

void Account::deposit(long double depositAmount)
{
	balance += depositAmount;

	Transaction newTransaction(depositAmount, "deposit");
	history.push_back(newTransaction);
}

void Account::deposit(std::string depositAmount)
{
	long double deposit = std::stold(depositAmount);
	balance += deposit;

	Transaction newTransaction(deposit, "deposit");
	history.push_back(newTransaction);
}

void Account::withdraw(long double withdrawAmount)
{
	balance -= withdrawAmount;

	Transaction newTransaction(withdrawAmount, "withdrawal");
	history.push_back(newTransaction);
}

void Account::withdraw(std::string withdrawAmount)
{
	long double withdraw = std::stold(withdrawAmount);
	balance -= withdraw;

	Transaction newTransaction(withdraw, "withdrawal");
	history.push_back(newTransaction);
}

std::string Account::toString() 
{
	return type + " | Balance: \x9C" + std::to_string(balance);
}

void Account::toConsole()
{
	std::cout << type << " | Balance: \x9C" << std::to_string(balance) << std::endl;
	for (Transaction selectedTransaction : history)
	{
		std::cout << selectedTransaction.toString();
	}
}