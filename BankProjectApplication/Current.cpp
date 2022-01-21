#include "Current.h"

Current::Current(long double startBalance) : Account(startBalance)
{
	// We simply need to define account type, as the constructor for account has already dealt with the balance
	type = "Current account";
	minBalance = -500; // Allow an overdraft of £500
	std::cout << "Current account created!" << std::endl; // Assert the account was created
}