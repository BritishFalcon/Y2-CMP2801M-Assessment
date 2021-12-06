class InterestEarning
{

protected:

	InterestEarning(long double newInterestRate);
	long double interestRate; // Using long double in order to maintain native multiplication with balance from Account (as well as ensuring calculations are performed with maximum precision)

};