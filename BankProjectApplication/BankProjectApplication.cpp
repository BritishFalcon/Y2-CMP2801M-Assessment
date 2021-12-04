/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for "LincBank" Assessment Item 1
Semester A 2021

Written by James Brown (jamesbrown@lincoln.ac.uk)
Modified for submission by Benjamin Griffiths (25199556@students.lincoln.ac.uk)

During marking, we will use the exact same notation
as provided in the brief, so make sure you follow that guideline.

You should avoid removing parts of this driver program, but
add to it the necessary code to produce your implementation.

Good luck!

GitHub Repo - https://github.com/BritishFalcon/Y2-CMP2801M-Assessment
------------------------------------------------------ */

#define _CRT_SECURE_NO_WARNINGS

#include "Account.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <ctime>
#include <string>

using namespace std;

int main()
{
	std::vector <std::string> parameters;
	std::string userCommand;

	std::vector<Account*> accountDatabase;
	// you may also want to store a collection of opened accounts here

	std::cout << "~~~ Welcome to LincBank! ~~~" << std::endl;

	while (userCommand != "exit")
	{
		parameters.clear(); // clear ready for next command
		std::cout << std::endl << ">>> ";

		std::getline(std::cin, userCommand);
		char* cstr = new char[userCommand.length() + 1];
		strcpy(cstr, userCommand.c_str());

		char* token;
		token = strtok(cstr, " "); // *** Works like split from Python, splits user's input into individual tokens (each parameter, seperated by space in this case)

		while (token != NULL) // *** While loop to take the tokens and turn them into a collection of parameters
		{
			parameters.push_back(token); // *** Push each token into parameters
			token = strtok(NULL, " ");
		}

		// Define all commands as per the brief
		std::string command = parameters[0];

		if (command.compare("options") == 0)
		{
			// display the various commands to the user
		}
		else if (command.compare("open") == 0)
		{
			std::cout << "Open an account?" << endl;
			std::string accountType = parameters[1];
			std::string depositParameter = parameters[2];

			Account* newAccount;

			long double initialDeposit = stold(depositParameter);

			if (accountType.compare("1") == 0)
			{
				newAccount = new Current(initialDeposit);
			}

			if (accountType.compare("2") == 0)
			{
				newAccount = new Savings(initialDeposit); // Normal Savings (TBC)
			}

			if (accountType.compare("3") == 0)
			{
				newAccount = new Savings(initialDeposit); // ISA Savings (TBC)
			}

			accountDatabase.push_back(newAccount);

			// allow a user to open an account
			// e.g., Account* a = new Savings(...);

		}
		else if (command.compare("view") == 0)
		{
			// display an account according to an index (starting from 1)
			// alternatively, display all accounts if no index is provided
		}
		else if (command.compare("withdraw") == 0)
		{
			// allow user to withdraw funds from an account
		}
		else if (command.compare("deposit") == 0)
		{
			// allow user to deposit funds into an account
		}
		else if (command.compare("transfer") == 0)
		{
			// allow user to transfer funds between accounts
			// i.e., a withdrawal followed by a deposit!
		}
		else if (command.compare("project") == 0)
		{
			// compute compound interest t years into the future
		}
		//else if (command.compare("search"))
		//{
		//	allow users to search their account history for a transaction
		//  (this is a stretch task)
		//}

	}

	std::cout << "Press any key to quit...";
	std::getchar();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file