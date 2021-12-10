#include "Savings.h"

Savings::Savings(bool isISA, long double startBalance) : Account(startBalance), InterestEarning()
{
	if (isISA)
	{
		interestRate = 0.0115;
		type = "ISA";
		std::cout << "ISA created" << std::endl;
	}
	else
	{
		interestRate = 0.0085;
		type = "Saving account";
		std::cout << "Savings created" << std::endl;
	}
}

long double Savings::computeInterest(long double years)
{
	return computeInterest(balance, years);
}