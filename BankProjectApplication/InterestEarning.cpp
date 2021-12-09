#include "InterestEarning.h"

InterestEarning::InterestEarning() {}

long double InterestEarning::computeInterest(long double start, long double years)
{
	long double interestMonth = start * (1.00 + (interestRate / 12));
	return pow(interestMonth, years*12);
}