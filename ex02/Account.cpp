/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 11:49:33 by root              #+#    #+#             */
/*   Updated: 2025/09/10 11:28:39 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

/*#include <iostream>	//std::cout, std::endl
#include <iomanip>	//std::setw, std:setfill
#include <ctime>	//std::time, std::localtime*/

//------------------------Initialization of static vars ------------------------

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//------------------------CONSTRUCTOR                   ------------------------

/**
* @brief	Default constructor for Account.
*/

Account::Account(void) 
{
	
}

/**
* @brief	Construct a new Account with an initial deposit.
*			- Initializes the account with the following:
*				* _accountIndex: assigned based on total accounts created
*				(_nbAccounts)
*				* _amount: set to initial_deposit
*				* _nbDeposits, _nbWithdrawals: set to 0
*			- Updates global statics:
*				* _nbAccounts incremented by 1
*				* _totalAmount increased by initial_deposit
*			- Logs account creatin with timestamp, index, and initial amount
*
* @param initial_deposit	Amount to initialize the account with.
*/

Account::Account( int initial_deposit )
{
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	Account::_nbAccounts ++;
	Account::_totalAmount += initial_deposit;
	
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";created" << std::endl;   
}

//------------------------DESTRUCTOR                    ------------------------

/**
* @brief	Destructor the Account object.
*			- Logs account closure with timestamp, index, and final amount.
*
*/

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";closed" << std::endl;
}

//------------------------PRIVATE HELPERS               ------------------------

/**
* @brief	Prints the current timestamp in [YYYYMMDD_HHMMSS] format.
*			- std::time() gets the current time as seconds since Epoch 
*			(Jan 1, 1970)
*			- std::localtime() converts to local time structure (year, month,
*			day, hout, min, sec)
*			- tm_year: year since 1900, needs +1900 to obtain current year
*			- tm_mon: 0-11, needs +1 to obtain 1-12 range
*			- tm_hor: 0-23
*			- tm_min: 0-59
*			- tm_sec: 0-60 (includes leap second)
*
*			- std:setw(2): ensures each value have 2 digits
*			- std::setfill('0'): fills with 0 if needed
*
* @param initial_deposit	Amount to initialize the account with.
*/

void	Account::_displayTimestamp(void)
{
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);

	std::cout << "["
			  << (now->tm_year + 1900)
			  << std::setw(2) << std::setfill('0') << (now->tm_mon + 1)
			  << std::setw(2) << std::setfill('0') << now->tm_mday
			  << "_"
			  << std::setw(2) << std::setfill('0') << now->tm_hour
			  << std::setw(2) << std::setfill('0') << now->tm_min
			  << std::setw(2) << std::setfill('0') << now->tm_sec
			  << "] ";
}

//------------------------PUBLIC FUNCTIONS    		    ------------------------

//Static getters

/**
* @brief	Get the total number of accounts created.
*
* @return int	Total accounts (_nbAccounts).
*/

int	Account::getNbAccounts( void )
{
	return (Account:: _nbAccounts);
}

/**
* @brief	Get the total amount across all accounts.
*
* @return int	Sum of all account balances (_totalAmount).
*/

int	Account::getTotalAmount( void )
{
	return (Account:: _totalAmount);
}

/**
* @brief	Get the total number of deposits made across all accounts.
*
* @return int	Total deposits (_totalNbDeposits).
*/

int	Account::getNbDeposits( void )
{
    return (Account:: _totalNbDeposits);
}

/**
* @brief	Get the total number of withdrawals made accross all accounts.
*
* @return int	Total withdrawals (_totalNbWithdrawals).
*/

int	Account::getNbWithdrawals( void )
{
    return (Account:: _totalNbWithdrawals);
}

//--------------------

/**
* @brief	Display global statistics for all accounts.
*			Prints a single line containing:
*			- The timestamp
*			- Total accounts
*			- Total amount
*			- Total deposits
*			- Total withdrawals
*
*/

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts()
			  << ";total:" << Account::getTotalAmount()
			  << ";deposits:" << Account::getNbDeposits()
			  << ";withdrawals:" << Account::getNbWithdrawals() 
			  << std::endl;
}

/**
* @brief	Makes a deposit to this account
*			- Updates:
*				* Account's _amount and _nbDeposits
*				* Global _totalAmount and _totalDeposits
*			- Logs the operation with timestamp, index, previous amount,
*			deposit amount, new amount, and total number of deposits
*
* @param deposit	Amount to deposit into the account.
*/

void	Account::makeDeposit( int deposit )
{
	int previousAmount = this->_amount;
	
	this->_amount = previousAmount + deposit;
	this->_nbDeposits ++;

	Account::_totalAmount += deposit;
	Account::_totalNbDeposits ++;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";p_amount:" << previousAmount
			  << ";deposit:" << deposit
			  << ";amount:" << this->_amount
			  << ";nb_deposits:" << this->_nbDeposits
			  << std::endl;
}

/**
* @brief	Attempts to withdrawal an amount from this account.
*			- Checks if the withdrawal is possible (balance sufficient).
*			- If insufficient funds, logs a message and returns false.
*			- Otherwise, updates:
*				* Account's _amount and _nbWithdrawals
*				* Global _totalAmount and _totalNbWithdrawals
*			- Logs the operation with timestamp, index, previous amount, 
*			withdrawal amount, new amount, and number of withdrawals
*
* @param withdrawal	Amount to withdraw
* @return bool	True if withdrawal suceeded, false if refused.
*/

bool	Account::makeWithdrawal( int withdrawal )
{
	int previousAmount = this->_amount;

	if (checkAmount() < withdrawal)
	{
		Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex
			 	  << ";p_amount:" << previousAmount
			 	  << ";withdrawal:refused" << std::endl;
		return (false);
	}
	
	this->_amount -= withdrawal;
	this->_nbWithdrawals ++;

	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals ++;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";p_amount:" << previousAmount
			  << ";withdrawal:" << withdrawal
			  << ";amount:" << this->_amount
			  << ";nb_withdrawals:" << this->_nbWithdrawals
			  << std::endl;

	return (true);
}

/**
* @brief	Returns the current balance of the account.
*
* @return int	Current account amount (_amount).
*/

int		Account::checkAmount( void ) const
{
	return (this->_amount) ;
}

/**
* @brief	Displays the current status of this account.
*			Prints a single line containing:
*			- Timestamp
*			- Account index
*			- Current amount
*			- Number of deposits
*			- Number of withdrawals
*/

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";deposits:" << this->_nbDeposits
			  << ";withdrawals:" << this->_nbWithdrawals
			  << std::endl;
}
