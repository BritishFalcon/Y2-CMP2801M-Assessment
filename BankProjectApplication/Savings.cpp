#include "Savings.h"

Savings::Savings(bool isISA, long double startBalance) : Account(startBalance), InterestEarning()
{
	type = "Saving account";
	std::cout << "Savings created" << std::endl;
	// Unfinished
}

long double Savings::computeInterest(long double years)
{
	return computeInterest(balance, years);
}