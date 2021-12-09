#include "Current.h"

Current::Current(long double startBalance) : Account(startBalance)
{
	type = "Current account";
	std::cout << "Current account created!" << std::endl;
}