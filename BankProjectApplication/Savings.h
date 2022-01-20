#pragma once

#ifndef SAVINGS_H
#define SAVINGS_H

#include "Account.h"
#include "InterestEarning.h"

class Savings : public Account, public InterestEarning // Inherit from both as specified
{

public:
	Savings(bool isISA, long double startBalance); // Rather than having a different definition for ISAs and Savings, contain them here (seen as the only difference is interest rate)
	using InterestEarning::computeInterest; // Inherited interest algorithm
	long double computeInterest(long double years);
};

#endif