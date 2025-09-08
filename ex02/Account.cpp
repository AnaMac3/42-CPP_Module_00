/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 11:49:33 by root              #+#    #+#             */
/*   Updated: 2025/09/08 16:29:39 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <iostream>	//std::cout, std::endl
#include <iomanip>	//std::setw, std:setfill
#include <ctime>	//std::time, std::localtime

//------------------------Inicialización de statics de clase------------------------

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//------------------------CONSTRUCTOR                   ------------------------
Account::Account(void) 
{
	
}

Account::Account( int initial_deposit )
{
	this->_accountIndex = Account::_nbAccounts; //current index
	this->_amount = initial_deposit;			//current amount
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	Account::_nbAccounts ++; //incrementa total de cuentas
	Account::_totalAmount += initial_deposit; //suma al total global 
	
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";created" << std::endl;   
}

//------------------------DESTRUCTOR                    ------------------------
Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";closed" << std::endl;
}

//------------------------PRIVATE HELPER FUNCTIONS      ------------------------
void	Account::_displayTimestamp(void)
{
	std::time_t t = std::time(0);	//current time
	std::tm* now = std::localtime(&t);	//convert to local time

	//Print in format [YYYYMMDD_HHMMSS]
	std::cout << "["
			  << (now->tm_year + 1900) //year since 1900?
			  << std::setw(2) << std::setfill('0') << (now->tm_mon + 1) //month [01-12]
			  << std::setw(2) << std::setfill('0') << now->tm_mday		//day [01-31]
			  << "_"
			  << std::setw(2) << std::setfill('0') << now->tm_hour
			  << std::setw(2) << std::setfill('0') << now->tm_min
			  << std::setw(2) << std::setfill('0') << now->tm_sec
			  << "] ";
}

//------------------------PUBLIC FUNCTIONS    		    ------------------------

//Static getters
int	Account::getNbAccounts( void )
{
	return (Account:: _nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account:: _totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (Account:: _totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return (Account:: _totalNbWithdrawals);
}

//--------------------

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts()
			  << ";total:" << Account::getTotalAmount()
			  << ";deposits:" << Account::getNbDeposits()
			  << ";withdrawals:" << Account::getNbWithdrawals() 
			  << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	int previousAmount = this->_amount;
	
	//Update account values
	this->_amount = previousAmount + deposit;
	this->_nbDeposits ++;

	//Update global values
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits ++;

	//Log	
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";p_amount:" << previousAmount
			  << ";deposit:" << deposit
			  << ";amount:" << this->_amount
			  << ";nb_deposits:" << this->_nbDeposits
			  << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int previousAmount = this->_amount;

	//Check if there is enough balance
	if (checkAmount() < withdrawal)
	{
		Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex
			 	  << ";p_amount:" << previousAmount
			 	  << ";withdrawal:refused" << std::endl;
		return (false);
	}
	
	//Update account values
	this->_amount -= withdrawal;
	this->_nbWithdrawals ++;

	//Update global values
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals ++;

	//Log	
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";p_amount:" << previousAmount
			  << ";withdrawal:" << withdrawal
			  << ";amount:" << this->_amount
			  << ";nb_withdrawals:" << this->_nbWithdrawals
			  << std::endl;

	return (true);
}

int		Account::checkAmount( void ) const
{
	return (this->_amount) ;
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";deposits:" << this->_nbDeposits
			  << ";withdrawals:" << this->_nbWithdrawals
			  << std::endl;
}
