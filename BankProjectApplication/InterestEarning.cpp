#include "InterestEarning.h"

InterestEarning::InterestEarning() {}

long double InterestEarning::computeInterest(long double start, long double years)
{
	long double interestMultiplier = powl(1.00 + (interestRate / 12.00), years * 12);
	return start * interestMultiplier;
}