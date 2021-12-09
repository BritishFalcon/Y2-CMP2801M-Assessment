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
	return +"--" + desc + ": \x9C" + CurrencyDblToStr(value, 2) + " on " + asctime(timestamp); 
	// Uses a fixed precision of 2 to remain compliant with sample execution which includes pence even if transaction value ends in .00 (unlike on account balance, which didn't show .00 in this case)
}