#include "Current.h"

Current::Current(long double startBalance) : Account(startBalance)
{
	// We simply need to define account type, as the constructor for account has already dealt with the balance
	type = "Current account";
	std::cout << "Current account created!" << std::endl; // Assert the account was created
}