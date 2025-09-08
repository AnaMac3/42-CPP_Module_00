/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 11:49:33 by root              #+#    #+#             */
/*   Updated: 2025/09/08 13:10:32 by root             ###   ########.fr       */
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

Account::Account( int initial_deposit ) //inicialización de atributos de cuenta individual
{
	this->_accountIndex = Account::_nbAccounts; //current index
	this->_amount = initial_deposit;			//current amount
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	Account::_nbAccounts ++; //incrementa total de cuentas
	Account::_totalAmount += initial_deposit; //suma al total global 
	
	Account::_displayTimestamp(); //hay que escribir esta función
	std::cout << "index:" << this->_accountIndex
			  << ";amount" << this->_amount
			  << ";created" << std::endl;
	//en formato: [19920104_091532] index:0;amount:42;created
    
}

//------------------------DESTRUCTOR                    ------------------------
Account::~Account( void )
{
	Account::_displayTimestamp(); //hay que escribir esta función
	std::cout << "index:" << this->_accountIndex
			  << ";amount" << this->_amount
			  << ";closed" << std::endl;
	//en formato: [19920104_091532] index:0;amount:42;closed
}

//------------------------PRIVATE HELPER FUNCTIONS      ------------------------
static void	_displayTimestamp( void )
{
	std::time_t t = std::time(nullptr);	//current time
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

static int	getNbAccounts( void )
{
    
}

static int	getTotalAmount( void )
{
    
}

static int	getNbDeposits( void )
{
    
}

static int	getNbWithdrawals( void )
{
    
}

static void	displayAccountsInfos( void )
{
    //imprime estado global de todas las cuentas 
    //[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
}


void	makeDeposit( int deposit )
{
    //aumenta el saldo de la cuenta y actualiza los contadores globales
}

bool	makeWithdrawal( int withdrawal )
{
    //disminuye el saldo si hay suficiente y actualiza los contadores
    //supongo que este tendrá que llamar a checkAmount
}

int		checkAmount( void )
{
    
}

void	displayStatus( void )
{
    //imprime estado de la cuenta individual
    //[19920104_091532] index:5;amount:0;created
    //[19920104_091532] index:4;p_amount:1234;deposit:87;amount:1321;nb_deposits:1

    //si no hay saldo suficiente para un retiro, imprime withdrawal:refused

    //el constructor y el destructor imprimen created y closed.

    //timestamps
}