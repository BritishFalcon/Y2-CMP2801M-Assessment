#include "Current.h"

Current::Current(long double startBalance) : Account(startBalance)
{
	std::cout << "Current account created!" << std::endl;
	// Unfinished
}

std::string Current::toString()
{
	std::string returnString = "Current account | ";
	std::string balanceStr = std::to_string(balance);
	return returnString + balanceStr;
}