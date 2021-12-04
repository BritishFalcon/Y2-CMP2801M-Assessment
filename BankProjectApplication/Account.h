class Account
{
public:

	void deposit(long double)
	{

	}

	void withdraw(long double)
	{

	}

	string toString()
	{

	}

protected:

	Account(long double startBalance)
	{
		balance = startBalance;
	}

	long double balance; // Using long double to store currency with high accuracy to avoid rounding issues (particularly once applying interest)

	//vector<Transaction> history;
};

class Transaction
{
public:
	string toString()
	{
		return to_string(value);
	}
private:
	string desc;
	tm timestamp;
	long double value;
};

class InterestEarning
{
public:
	InterestEarning(long double newInterestRate)
	{
		interestRate = newInterestRate;
	}
private:
	long double interestRate; // Using long double in order to maintain native multiplication with balance from Account (as well as ensuring calculations are performed with maximum precision)
};

class Current : public Account
{
public:
	Current(long double startBalance) : Account(startBalance)
	{
		cout << "Current account created!" << endl;
	}
};

class Savings : public Account, public InterestEarning
{

};