#include "Transaction.h"

Transaction::Transaction(long double transValue, std::string transDescription)
{
	// These three lines take the raw time and turn it into a time structure
	time_t rawTime;
	time(&rawTime);
	struct tm* timestampPtr = localtime(&rawTime);
	timestamp = asctime(timestampPtr); // Following this, it is preserved as a string in standard format

	value = transValue; // Pass the transaction value
	desc = transDescription; // Pass the transaction description
}

std::string Transaction::toString()
{
	return +"--" + desc + ": \x9C" + CurrencyDblToStr(value, 2) + " on " + timestamp; 
	// Uses a fixed precision of 2 to remain compliant with sample execution which includes pence even if transaction value ends in .00 (unlike on account balance, which didn't show .00 in this case)
}

long double Transaction::getValue()
{
	return value;
}