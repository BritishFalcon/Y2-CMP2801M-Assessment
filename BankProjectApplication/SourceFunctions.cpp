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