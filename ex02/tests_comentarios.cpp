// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"

int		main( void ) {

	typedef std::vector<Account::t>							  accounts_t; //Vector que almacena objetos Account de manera dinámica, crece a medida que se añaden elementos
	typedef std::vector<int>								  ints_t; //Vector que almacena ints de manera dinámica
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t; //iterator: tipo que permite recorrer un contenedor, similar a un puntero
																		//acc_int_t es un alias para un par de iteradores,
																		//first recorre accounts_t y seconds recorre ints_t

	//Inicialización de cuentas y vectores:
	//amounts: array de int con balances iniciales para cada cuenta
	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	//amounts_size: calcula el número de elementos del array
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );
	//accounts: vector de Account inicializado usando el rango [amounts, amounts + amounts_size]
	//esto implica que cada elemento de accounts se construye con un balance inicial
	accounts_t				accounts( amounts, amounts + amounts_size );
	//Guardamos iteradores al ppio y al final del vector accounts para recorrerlo después
	accounts_t::iterator	acc_begin	= accounts.begin();
	accounts_t::iterator	acc_end		= accounts.end();

	//Inicialización de depósitos y retiros:
	//d: array de depósitos a realizar en cada cuenta
	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };
	//
	size_t const		d_size( sizeof(d) / sizeof(int) );
	//deposits: vector de int creado a partir del array d
	ints_t				deposits( d, d + d_size );
	//Iteradores para recorrer los depósitos
	ints_t::iterator	dep_begin	= deposits.begin();
	ints_t::iterator	dep_end		= deposits.end();

	//w: array de retiros
	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const		w_size( sizeof(w) / sizeof(int) );
	//withdrawals: vector de int creado a partir del array w
	ints_t				withdrawals( w, w + w_size );
	ints_t::iterator	wit_begin	= withdrawals.begin();
	ints_t::iterator	wit_end		= withdrawals.end();

	//Modificar infor inicial
	//Account::displayAccountsInfos() -> función estática que porbablemente
	//muestra el estado inicial de todas las cuentas (num de cuenta, balance total)
	Account::displayAccountsInfos();
	//recorre todas las cuentas y llama a displayStatus() para cada una
	//std::mem_fun_ref(&Account::displayStatus) -> permite pasar un método miembro de
	//objeto a for_each
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	//Hacer depósitos
	//Se crean un par de iteradores it: it.first recorre las cuentas, 
	//it.second recorre los depósitos. 
	//Mientras no lleguemos al final de ninguno de los dos vectores, 
	//llamamos a makeDeposit de la cuenta actual y le pasamos el depósito correspondiente
	for ( acc_int_t it( acc_begin, dep_begin );
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeDeposit( *(it.second) );
	}

	//Mostrar infor después de los depósitos
	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	//Hacer retiros
	//Igual que depósitos, pero con makeWithdrawal
	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
	}

	//Mostrar infor final
	//estado final después de todas las operaciones
	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	return 0;
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
