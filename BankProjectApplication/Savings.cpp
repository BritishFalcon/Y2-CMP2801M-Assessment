#include "Savings.h"

Savings::Savings(bool isISA, long double startBalance) : Account(startBalance), InterestEarning()
{
	if (isISA) // There's only two possible inputs for this, so we can just use an if-else
	{
		interestRate = 0.0115; // Interest is higher on ISA, but it's otherwise the same
		type = "ISA";
		std::cout << "ISA created!" << std::endl; // Assert the correct account type has been created
	}
	else
	{
		interestRate = 0.0085; // Lower interest on savings accounts
		type = "Saving account";
		std::cout << "Savings created!" << std::endl; // Assert the correct account type has been created
	}
}

// Create an underflow where balance isn't given, as the account is able to simply use its own balance to interact with the inherited function
long double Savings::computeInterest(long double years)
{
	return computeInterest(balance, years);
}