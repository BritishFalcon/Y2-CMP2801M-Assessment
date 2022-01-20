#pragma once

#ifndef CURRENT_H
#define CURRENT_H

#include "Account.h"

class Current : public Account // Inherit from Base Class Account
{

public:

	Current(long double startBalance); // Method override specific to current accounts

	// Everything else is inherited from Account
};

#endif