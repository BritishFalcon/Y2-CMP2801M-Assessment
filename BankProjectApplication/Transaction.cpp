#include "Transaction.h"

Transaction::Transaction(long double transValue, std::string transDescription)
{
	time_t rawTime;
	time(&rawTime);
	timestamp = localtime(&rawTime);

	value = transValue;
	desc = transDescription;
}

std::string Transaction::toString()
{
	return +"--" + desc + ": \x9C" + std::to_string(value) + " on " + asctime(timestamp);
}