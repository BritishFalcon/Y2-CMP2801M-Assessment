#include "Account.h"
#include "InterestEarning.h"

class Savings : public Account, public InterestEarning
{

public:

	Savings(bool isISA, long double startBalance);

};