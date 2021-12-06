#pragma once

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <ctime>

class Transaction
{

public:

	std::string toString();

	Transaction(long double, tm, std::string);

};

#endif