#pragma once

#ifndef INTERESTEARNING_H
#define INTERESTEARNING_H

#include <iostream>
#include <math.h>
#include "SourceFunctions.h" //REMOVE

class InterestEarning
{
protected:
	InterestEarning();
	long double interestRate; // Using long double in order to maintain native multiplication with balance from Account (as well as ensuring calculations are performed with maximum precision)
	virtual long double computeInterest(long double start, long double years);
};

#endif