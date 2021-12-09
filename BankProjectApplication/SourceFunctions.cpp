#include "SourceFunctions.h"

void showOptions()
{
	std::cout
		<< "open type initial_deposit: open a current (1), savings (2) or ISA (3) account" << std::endl
		<< "view [index]: view balance and recent transactions" << std::endl
		<< "withdraw sum: withdraw funds from most recently viewed account" << std::endl
		<< "deposit sum: deposit funds into most recently viewed account" << std::endl
		<< "transfer src dest sum: transfer funds between accounts" << std::endl
		<< "project years: project balance forward in time" << std::endl
		<< "exit: close this application" << std::endl
		<< "options: view these options again" << std::endl
	;
}

std::string CurrencyDblToStr(long double givenDbl, int precision)
{
	std::ostringstream returnStream;
	returnStream << std::fixed;
	returnStream.precision(precision);
	returnStream << givenDbl;

	return returnStream.str();
}

std::string CurrencyDblToStr(long double givenDbl)
{
	if (fmod(givenDbl, 1.00) == 0)
	{
		return CurrencyDblToStr(givenDbl, 0);
	}
	else
	{
		return CurrencyDblToStr(givenDbl, 2);
	}
}