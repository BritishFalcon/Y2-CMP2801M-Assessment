#pragma once

#ifndef SAVINGS_H
#define SAVINGS_H

#include "Account.h"
#include "InterestEarning.h"

class Savings : public Account, public InterestEarning
{

public:
	Savings(bool isISA, long double startBalance);
	using InterestEarning::computeInterest;
	long double computeInterest(long double years);
};

#endif