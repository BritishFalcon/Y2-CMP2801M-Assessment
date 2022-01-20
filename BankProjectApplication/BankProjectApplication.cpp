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

#include "Current.h"
#include "Savings.h"
#include "SourceFunctions.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <ctime>
#include <string>

int main()
{
	std::vector <std::string> parameters;
	std::string userCommand;

	std::vector<Account*> accountDatabase;
	Account* selectedAccount = nullptr;
	Savings* selectedSaving = nullptr;

	time_t rawTime;
	struct tm* myTime;
	// you may also want to store a collection of opened accounts here

	std::cout << "~~~ Welcome to LincBank! ~~~" << std::endl;

	showOptions();

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
			showOptions(); // Using a function to prevent code repeating from initial printing of options
		}
		else if (command.compare("open") == 0)
		{
			std::string accountType = parameters[1];
			std::string depositParameter = parameters[2];

			long double initialDeposit = stold(depositParameter);

			if (accountType.compare("1") == 0)
			{
				selectedAccount = new Current(initialDeposit);
			}

			
			if (accountType.compare("2") == 0)
			{
				selectedAccount = new Savings(0, initialDeposit);
			}

			
			if (accountType.compare("3") == 0)
			{
				selectedAccount = new Savings(1, initialDeposit);
			}
			

			accountDatabase.push_back(selectedAccount);
		}
		else if (command.compare("view") == 0)
		{
			if (accountDatabase.size() > 0)
			{
				if (parameters.size() == 1)
				{
					for (Account* eachAccount : accountDatabase)
					{
						eachAccount->toConsole();
					}
				}
				else if (parameters.size() == 2)
				{	
					std::string accountNumber = parameters[1];
					try
					{
						if ((0 < std::stoi(accountNumber)) && (std::stoi(accountNumber) <= accountDatabase.size()))
						{
							std::string indexStr = parameters[1];
							int indexInt = std::stoi(indexStr) - 1;
							selectedAccount = accountDatabase[indexInt];

							selectedAccount->toConsole();
						}
						else
						{
							std::cout << "There is no account with this number, try again!" << std::endl;
						}
					}
					catch (...)
					{
						std::cout << "Invalid input, try again!" << std::endl;
					}
				}
				else
				{
					std::cout << "Wrong number of parameters used, please try again!" << std::endl;
				}
			}
			else
			{
				std::cout << "There are no accounts to view!" << std::endl;
			}
			
			// display an account according to an index (starting from 1)
			// alternatively, display all accounts if no index is provided
		}
		else if (command.compare("withdraw") == 0)
		{
			try
			{
				std::string withdrawAmount = parameters[1];
				selectedAccount->withdraw(withdrawAmount, "withdraw");
				selectedAccount->toConsole();
			}
			catch (...)
			{
				std::cout << "Invalid input, try again!" << std::endl;
			}
			// allow user to withdraw funds from an account
		}
		else if (command.compare("deposit") == 0)
		{
			try
			{
				if (selectedAccount != NULL)
				{
					std::string depositAmount = parameters[1];
					selectedAccount->deposit(depositAmount, "deposit");
					selectedAccount->toConsole();
				}
				else
				{
					std::cout << "No account selected! Try again!" << std::endl;
				}
			}
			catch (...)
			{
				std::cout << "Invalid input, try again!" << std::endl;
			}
			// allow user to deposit funds into an account
		}
		else if (command.compare("transfer") == 0)
		{
			if (accountDatabase.size() > 0)
			{
				if (parameters.size() == 4)
				{
					try
					{
						std::string sourceAccountStr = parameters[1];
						std::string destinationAccountStr = parameters[2];
						std::string transferStr = parameters[3];

						int sourceAccountInt = std::stoi(sourceAccountStr) - 1;
						int destinationAccountInt = std::stoi(destinationAccountStr) - 1;

						long double transferDbl = stold(transferStr);

						if (sourceAccountStr != destinationAccountStr)
						{
							if ((sourceAccountInt >= 0) && (sourceAccountInt <= accountDatabase.size() - 1))
							{
								if ((destinationAccountInt >= 0) && (destinationAccountInt <= accountDatabase.size() - 1))
								{
									selectedAccount = accountDatabase[sourceAccountInt];

									selectedAccount->withdraw(transferDbl, "transfer");
									selectedAccount->toConsole();

									selectedAccount = accountDatabase[destinationAccountInt];

									selectedAccount->deposit(transferDbl, "transfer");
									selectedAccount->toConsole();

									std::cout << "Transfer successful!" << std::endl;
								}
								else
								{
									std::cout << "Destination account does not exist, try again!" << std::endl;
								}
							}
							else
							{
								std::cout << "Source account does not exist, try again!" << std::endl;
							}
						}
						else
						{
							std::cout << "You cannot transfer to and from the same account!" << std::endl;
						}
					}
					catch (std::invalid_argument)
					{
						std::cout << "Invalid input, try again!" << std::endl;
					}
				}
				else
				{
					std::cout << "Wrong number of parameters used, please try again!" << std::endl;
				}
			}
			else
			{
				std::cout << "There are no accounts to transfer to or from!" << std::endl;
			}

			// allow user to transfer funds between accounts
			// i.e., a withdrawal followed by a deposit!
		}
		else if (command.compare("project") == 0)
		{
			if (parameters.size() == 2)
			{
				if (selectedAccount->getType() != "Current account")
				{
					try
					{
						std::string yearsStr = parameters[1];
						long double yearsDbl = std::stold(yearsStr);


						selectedSaving = static_cast<Savings*>(selectedAccount);
						long double projectedBalance = selectedSaving->computeInterest(yearsDbl);
						std::cout << CurrencyDblToStr(projectedBalance) << std::endl;
					}
					catch (...)
					{
						std::cout << "Invalid input, try again!" << std::endl;
					}
				}
				else
				{
					std::cout << "Selected account is not a savings account, please try again!" << std::endl;
				}
			}
			else
			{
				std::cout << "Wrong number of parameters used, please try again!" << std::endl;
			}
			// compute compound interest t years into the future
		}
		//else if (command.compare("search"))
		//{
		//	allow users to search their account history for a transaction
		//  (this is a stretch task)
		//}
		else
		{
			std::cout << "Unknown command, try again" << std::endl;
		}

	}

	std::cout << "Press any key to quit...";
	std::getchar();

	return 0;
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