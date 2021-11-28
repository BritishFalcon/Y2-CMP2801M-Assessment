
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Account
{
public:
	//void deposit(long double);
protected:
	long double balance; // Using long double to store currency with high accuracy to avoid rounding issues (particularly once applying interest)
	vector<Transaction> history;
};

class Transaction
{
protected:
	string desc;
	tm timestamp;
	long double value; 
};