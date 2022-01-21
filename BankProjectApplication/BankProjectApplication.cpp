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
	std::vector<std::string> parameters; // As the user is typing multiple options into the terminal, it makes sense to seperate each command in a list
	std::string userCommand; // This will be the first command; the one used to determine the action that will be done

	std::vector<Account*> accountDatabase; // Store pointers to accounts
	Account* selectedAccount = nullptr; // Store the current account pointer from the above database
	Savings* selectedSaving = nullptr; // Similar to above, but specifically for a saving account, not just any type of account

	// Used to obtain the time
	time_t rawTime;
	struct tm* myTime;

	// Introductory message
	std::cout << "~~~ Welcome to LincBank! ~~~" << std::endl;

	// Show available commands; this is a function as the user can ask to repeat it, and without a function, it would be required to write the same thing twice (needless repetition)
	showOptions();

	while (userCommand != "exit") // Keep going indefenitely until stopped...
	{
		parameters.clear(); // Clear ready for next command
		std::cout << std::endl << ">>> "; // Add a >>> to each line so the user knows it's somewhere they can input

		std::getline(std::cin, userCommand); // Take the user's input
		char* cstr = new char[userCommand.length() + 1]; // Create a pointer to copy the input
		strcpy(cstr, userCommand.c_str());

		char* token;
		token = strtok(cstr, " "); // Splits user's input into individual tokens (each parameter, seperated by space in this case)

		while (token != NULL) // While loop to take the tokens and turn them into a collection of parameters
		{
			parameters.push_back(token); // Push each token into parameters list
			token = strtok(NULL, " "); // Split by a space
		}

		// Define all commands as per the brief
		std::string command = parameters[0];

		if (command.compare("options") == 0)
		{
			showOptions(); // Using a function to prevent code repeating from initial printing of options, as mentioned before
		}
		else if (command.compare("open") == 0)
		{
			try
			{
				std::string accountType = parameters[1]; // Parameter 1 (0 defines which command) is the account type; current, saving or ISA
				std::string depositParameter = parameters[2]; // How much to deposit into, given by the user in the second parameter

				long double initialDeposit = stold(depositParameter); // Convert the deposit to a long double, used here to represent money

				// 1 is a current account
				if (initialDeposit >= 0)
				{
					if (accountType.compare("1") == 0)
					{
						selectedAccount = new Current(initialDeposit);
						accountDatabase.push_back(selectedAccount); // Once the new account is created, add it to the database
					}

					// 2 is a savings account
					if (accountType.compare("2") == 0)
					{
						selectedAccount = new Savings(0, initialDeposit);
						accountDatabase.push_back(selectedAccount); // Once the new account is created, add it to the database
					}

					// 3 is an ISA account; but this uses class Savings
					if (accountType.compare("3") == 0)
					{
						if (initialDeposit >= 1000)
						{
							selectedAccount = new Savings(1, initialDeposit);
							accountDatabase.push_back(selectedAccount); // Once the new account is created, add it to the database
						}
						else
						{
							std::cout << "ISA initial balance must be more than 1000 pounds"; // Fulfill the requirement that ISAs start with over £1000
						}
					}
				}
				else
				{
					std::cout << "Initial deposit cannot be a negative number!";
				}
			}
			catch (...)
			{
				std::cout << "Invalid input, try again!" << std::endl;
			}
		}
		else if (command.compare("view") == 0) // View/select an account
		{
			if (accountDatabase.size() > 0) // Ensure this isn't attempted before any accounts are created
			{
				if (parameters.size() == 1) // If there is only one token in parameters, they've simply typed 'view', so print all accounts
				{
					for (Account* eachAccount : accountDatabase) // Go through each account and return it
					{
						eachAccount->toConsole(); // Gives account information and transactions
					}
				}
				else if (parameters.size() == 2) // We can also accept one parameter to the command; account number
				{	
					std::string accountNumber = parameters[1]; // Take the parameter from input
					try // Use error trapping here to prevent an error (e.g if a user types a non-numeric account number)
					{
						if ((0 < std::stoi(accountNumber)) && (std::stoi(accountNumber) <= accountDatabase.size())) // Ensure that account number is bigger than 0 and exists in the scope of the database
						{
							int indexInt = std::stoi(accountNumber) - 1; // The database starts at 1 for user reabability, so consider it here
							selectedAccount = accountDatabase[indexInt]; // Select the account with the given number

							selectedAccount->toConsole(); // Output account information and transactions
						}
						else
						{
							std::cout << "There is no account with this number, try again!" << std::endl; // Tell the user if they select (a numeric but) an out of range account number
						}
					}
					catch (...)
					{
						std::cout << "Invalid input, try again!" << std::endl; // The code will end up here if conversion to integer fails, indicating a non-compliant entry format (e.g, alpha input into the int index)
					}
				}
				else
				{
					std::cout << "Wrong number of parameters used, please try again!" << std::endl; // Disallow anything other than 0 or 1 parameters (not counting the command)
				}
			}
			else
			{
				std::cout << "There are no accounts to view!" << std::endl; // If no accounts have been created yet, prevent issue by outputting this here
			}
		}
		else if (command.compare("withdraw") == 0)
		{
			try
			{
				// Withdraw contains type overflow, so we can pass a string directly, but to check it against minimum balance first, we'll convert it anyway
				long double withdrawAmount = std::stold(parameters[1]);
				if (withdrawAmount > 0)
				{
					if (selectedAccount->getBalance() - withdrawAmount >= selectedAccount->getMinBalance())
					{
						selectedAccount->withdraw(withdrawAmount, "withdraw"); // Withdrawal amount will automatically be considered negative to remove from account
						selectedAccount->toConsole(); // Output account information and transactions (including this one)
					}
					else
					{
						std::cout << "Withdrawal exceeds overdraft limit!" << std::endl;
					}
				}
				else
				{
					std::cout << "You cannot withdraw a negative amount or zero!" << std::endl;
				}
			}
			catch (...) // If the withdraw conversion from string to long double fails, it'll throw an error that will end up here
			{
				std::cout << "Invalid input, try again!" << std::endl; // Tell the user they had an invalid input (usually non-numeric withdrawal value)
			}

		}
		else if (command.compare("deposit") == 0)
		{
			try
			{
				if (selectedAccount != NULL) // An alternative approach to withdraw, rather than checking the database, checking the pointer to see if it's null
				{

					// As with withdraw, string input for deposit value is supported but not used here
					long double depositAmount = std::stold(parameters[1]);
					if (depositAmount > 0)
					{
						selectedAccount->deposit(depositAmount, "deposit");
						selectedAccount->toConsole(); // Output account information and transactions (including this one)
					}
					else
					{
						std::cout << "You cannot deposit a negative amount or zero!" << std::endl;
					}
				}
				else
				{
					std::cout << "No account selected! Try again!" << std::endl; // If the pointer is null, no account is selected. This should only be possible if the database is empty, as the pointer is never made null again after this
				}
			}
			catch (...)
			{
				std::cout << "Invalid input, try again!" << std::endl; // Again, throw if input is invalid (if conversion to long double fails, primarily)
			}
			// allow user to deposit funds into an account
		}
		else if (command.compare("transfer") == 0)
		{
			if (accountDatabase.size() > 0) // Prevent issue by ensuring the database is more than 0 (there is a seperate error given for if there's one account and you try to transfer to itself)
			{
				if (parameters.size() == 4) // Here we require command, source, destination and amount - no more no less
				{
					try
					{
						// Store input parameters - see variable names
						std::string sourceAccountStr = parameters[1];
						std::string destinationAccountStr = parameters[2];
						std::string transferStr = parameters[3];

						int sourceAccountInt = std::stoi(sourceAccountStr) - 1; // Minus 1 as user sees account index as starting at 1 rather than 0
						int destinationAccountInt = std::stoi(destinationAccountStr) - 1;

						long double transferDbl = stold(transferStr); // Convert the money part to long double

						if (sourceAccountStr != destinationAccountStr) // Ensure the user doesn't try to send money to the same account it came from
						{
							if ((sourceAccountInt >= 0) && (sourceAccountInt <= accountDatabase.size() - 1)) // If the source account number exists in the database
							{
								if ((destinationAccountInt >= 0) && (destinationAccountInt <= accountDatabase.size() - 1)) // And the destination account number exists in the database
								{
									if (transferDbl > 0)
									{
										// Select the first account
										selectedAccount = accountDatabase[sourceAccountInt];

										if (selectedAccount->getBalance() - transferDbl >= selectedAccount->getMinBalance())
										{
											// Take money from the source account; first part of the transaction
											selectedAccount->withdraw(transferDbl, "transfer");
											selectedAccount->toConsole();

											// Select the second account
											selectedAccount = accountDatabase[destinationAccountInt];

											// Give the same amount of money to the destination account
											selectedAccount->deposit(transferDbl, "transfer");
											selectedAccount->toConsole();

											// Assert the transaction was a success to the user
											std::cout << "Transfer successful!" << std::endl;
										}
										else
										{
											std::cout << "Withdrawal exceeds overdraft limit!" << std::endl;
										}
									}
									else
									{
										std::cout << "You cannot transfer a negative amount or zero!" << std::endl;
									}
								}
								else
								{
									std::cout << "Destination account does not exist, try again!" << std::endl; // Seperate error from source account in order to provide clarity to the user on what is causing an error based on their input
								}
							}
							else
							{
								std::cout << "Source account does not exist, try again!" << std::endl; // Same as above, but for the source account
							}
						}
						else
						{
							std::cout << "You cannot transfer to and from the same account!" << std::endl; // Tell the user than transferring to and from the same account does... nothing
						}
					}
					catch (std::invalid_argument)
					{
						std::cout << "Invalid input, try again!" << std::endl; // Catch invalid argument for if the long double conversion fails
					}
				}
				else
				{
					std::cout << "Wrong number of parameters used, please try again!" << std::endl; // Tell user if they entered too many or too few parameters
				}
			}
			else
			{
				std::cout << "There are no accounts to transfer to or from!" << std::endl; // Let the user know if there are no accounts, as you can't transfer from nothing to nothing
			}
		}
		else if (command.compare("project") == 0) // Project future balance of a savings account (based on its class-specific interest)
		{
			if (parameters.size() == 2) // Ensure only command and one parameter is used (years)
			{
				if (selectedAccount->getType() != "Current account") // Ensure the account is not a current account, as that doesn't provide Interest Earning in this implementation
				{
					try // To catch invalid input of years
					{
						std::string yearsStr = parameters[1];
						long double yearsDbl = std::stold(yearsStr); // Convert years to long double for easy multiplication with account value


						selectedSaving = static_cast<Savings*>(selectedAccount); // Select the already selected account, but with a savings pointer rather than a universal account pointer
						long double projectedBalance = selectedSaving->computeInterest(yearsDbl); // Run the compute interest function build into savings accounts
						std::cout << CurrencyDblToStr(projectedBalance) << std::endl; // Output with an automatic precision provided by CurrencyDblToStr
					}
					catch (...)
					{
						std::cout << "Invalid input, try again!" << std::endl; // Prevent invalid input
					}
				}
				else
				{
					std::cout << "Selected account is not a savings account, please try again!" << std::endl; // Current accounts can't be used here - it would throw an error when casting a savings account pointer, and it doesn't have a compute interest function
				}
			}
			else
			{
				std::cout << "Wrong number of parameters used, please try again!" << std::endl; // Ensure correct parameter count
			}
		}
		else if (command.compare("search") == 0) // Stretch task
		{
			if (parameters.size() == 2) // Only two parameters can be used here; command and search value
			{
				try // To catch invalid search value
				{
					long double searchValue = stold(parameters[1]);
					std::vector<Transaction> searchResults = selectedAccount->searchTransaction(searchValue); // Use the function from accounts to return all matching transactions (in a vector of transactions, as there can be multiple results)
					for (Transaction selectedTransaction : searchResults) // Go through each match
					{
						std::cout << selectedTransaction.toString(); // And print its transaction information
					}
				}
				catch (...)
				{
					std::cout << "Invalid input, try again!" << std::endl; // Catch non-compliant user input
				}
			}
		}	
		else
		{
			std::cout << "Unknown command, try again" << std::endl; // Print this for if the command the user submits is invalid, better than printing nothing which may confuse the user
		}

	}

	// After the user decides to quit, run this...
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