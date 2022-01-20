#include "Account.h"

Account::Account(long double startBalance)
{
	balance = startBalance;

	Transaction newTransaction(startBalance, "initial deposit");
	history.push_back(newTransaction);
}

void Account::generateTransaction(long double transactionSum, std::string depositDescription)
{
	Transaction newTransaction(transactionSum, depositDescription);
	history.push_back(newTransaction);
}

// DEPOSIT
void Account::deposit(long double depositAmount, std::string depositDescription)
{
	balance += depositAmount;

	Transaction newTransaction(depositAmount, depositDescription);
	history.push_back(newTransaction);

}

void Account::deposit(std::string depositAmount, std::string depositDescription)
{
	long double makeDouble = std::stold(depositAmount);
	deposit(makeDouble, depositDescription);
}

// WITHDRAW
void Account::withdraw(long double withdrawAmount, std::string withdrawDescription)
{
	balance -= withdrawAmount;

	Transaction newTransaction(-withdrawAmount, withdrawDescription);
	history.push_back(newTransaction);
}

void Account::withdraw(std::string withdrawAmount, std::string withdrawDescription)
{
	long double makeDouble = std::stold(withdrawAmount);
	withdraw(makeDouble, withdrawDescription);
}

// ADDITIONAL FUNCTIONS
std::string Account::toString() 
{
	return type + " | Balance: \x9C" + CurrencyDblToStr(balance);
}

void Account::toConsole()
{
	std::cout << type << " | Balance: \x9C" << CurrencyDblToStr(balance) << std::endl;
	for (Transaction selectedTransaction : history)
	{
		std::cout << selectedTransaction.toString();
	}
}

std::string Account::getType()
{
	return type;
}