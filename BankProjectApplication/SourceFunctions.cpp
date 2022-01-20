#include "SourceFunctions.h"

void showOptions()
{
	std::cout // Provided options
		<< "open type initial_deposit: open a current (1), savings (2) or ISA (3) account" << std::endl
		<< "view [index]: view balance and recent transactions" << std::endl
		<< "withdraw sum: withdraw funds from most recently viewed account" << std::endl
		<< "deposit sum: deposit funds into most recently viewed account" << std::endl
		<< "transfer src dest sum: transfer funds between accounts" << std::endl
		<< "project years: project balance forward in time" << std::endl
		<< "search value: search for account transactions by their value" << std::endl
		<< "exit: close this application" << std::endl
		<< "options: view these options again" << std::endl
	;
}

std::string CurrencyDblToStr(long double givenDbl, int precision)
{
	// Use a stream to modify precision without affecting the main output stream
	std::ostringstream returnStream;
	returnStream << std::fixed;
	returnStream.precision(precision); // Set precision here
	returnStream << givenDbl;

	return returnStream.str(); // Return as a string which has had precision applied
}

std::string CurrencyDblToStr(long double givenDbl)
{
	if (fmod(givenDbl, 1.00) == 0) // If it's a decimal number (remainder when divided by zero) then it needs additional precision (2 digits for money)
	{
		return CurrencyDblToStr(givenDbl, 0); // For non-decimals; don't show .00
	}
	else
	{
		return CurrencyDblToStr(givenDbl, 2); // For decimals in money form; two places
	}
}