#include "Account.h"

Account::Account(long double startBalance)
{
	balance = startBalance;

	// Add a transaction to mark the conception of the account
	generateTransaction(startBalance, "initial deposit");
}

void Account::generateTransaction(long double transactionSum, std::string depositDescription)
{
	// Give the ability to create new transactions and add them to an internal history
	Transaction newTransaction(transactionSum, depositDescription);
	history.push_back(newTransaction);
}

// DEPOSIT
void Account::deposit(long double depositAmount, std::string depositDescription)
{
	balance += depositAmount; // Add as this is a deposit

	// Create a transaction for the deposit
	generateTransaction(depositAmount, depositDescription);
}

void Account::deposit(std::string depositAmount, std::string depositDescription)
{
	long double makeDouble = std::stold(depositAmount); // Convert to long double...
	deposit(makeDouble, depositDescription); ///...and call the original function, saving repetitive conversions in the main code
}

// WITHDRAW
void Account::withdraw(long double withdrawAmount, std::string withdrawDescription)
{
	balance -= withdrawAmount; // Minus as this is a withdrawal

	// Create a transaction for the withdrawal, signing it negatively to indicate money was deducted rather than added
	generateTransaction(-withdrawAmount, withdrawDescription);
}

void Account::withdraw(std::string withdrawAmount, std::string withdrawDescription)
{
	long double makeDouble = std::stold(withdrawAmount); // As before, convert to long double...
	withdraw(makeDouble, withdrawDescription); // ...and call the original withdraw function, saving repetition
}

// ADDITIONAL FUNCTIONS
std::string Account::toString() 
{
	return type + " | Balance: \x9C" + CurrencyDblToStr(balance); // Be able to represent the account information in an easily readible format
}

void Account::toConsole() // Print the full account details
{
	std::cout << toString() << std::endl; // Print the account brief (details)
	for (Transaction selectedTransaction : history) // Print each transaction associated with this account
	{
		std::cout << selectedTransaction.toString(); // Output currently selected transaction
	}
}

const std::string Account::getType()
{
	return type; // Return account type, e.g "Current account"
}

// Search for transactions by value on an account
std::vector<Transaction> Account::searchTransaction(long double searchValue)
{
	std::vector<Transaction> resultList; // Define a list of transactions ready to output any matches
	for (Transaction selectedTransaction : history) // Go through each transaction for checking
	{
		if (searchValue == selectedTransaction.getValue()) // If it's a match to the given parameter...
		{
			resultList.push_back(selectedTransaction); // Add it to the list of matches
		}
	}
	return resultList; // Return the completed list of matches
}

const long double& Account::getBalance()
{
	return balance;
}

const long double& Account::getMinBalance()
{
	return minBalance;
}