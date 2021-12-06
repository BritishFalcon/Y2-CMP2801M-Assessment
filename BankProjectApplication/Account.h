#include <string>
#include <ctime>
#include <iostream>

class Account
{

public:

	virtual void deposit(long double);

	virtual void withdraw(long double);

	virtual string toString();


protected:

	Account(long double startBalance);

	long double balance; // Using long double to store currency with high accuracy to avoid rounding issues (particularly once applying interest)

};
