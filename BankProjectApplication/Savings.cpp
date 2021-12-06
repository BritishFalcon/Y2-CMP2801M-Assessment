#include "Savings.h"
#include "Account.h"
#include "InterestEarning.h"

Savings::Savings(bool isISA, long double startBalance) : Account(startBalance), InterestEarning()
{
	std::cout << "Savings created" << std::endl;
	// Unfinished
}