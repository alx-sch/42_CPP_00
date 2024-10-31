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

	// Define types for convenience
	typedef std::vector<Account::t>							  accounts_t;
	typedef std::vector<int>								  ints_t;
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;

	// Initialize account balances
	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 }; // array of initial deposit amounts
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) ); // number of elements in the array
	accounts_t				accounts( amounts, amounts + amounts_size ); // initialize vector with array
	accounts_t::iterator	acc_begin	= accounts.begin(); // iterator to the beginning of the vector
	accounts_t::iterator	acc_end		= accounts.end(); // iterator to the end of the vector

	// Initialize deposit amounts
	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 }; // array of deposit amounts
	size_t const		d_size( sizeof(d) / sizeof(int) ); // number of elements in the array
	ints_t				deposits( d, d + d_size ); // initialize vector with array
	ints_t::iterator	dep_begin	= deposits.begin(); // iterator to the beginning of the vector
	ints_t::iterator	dep_end		= deposits.end(); // iterator to the end of the vector

	// Initialize withdrawal amounts
	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 }; // array of withdrawal amounts
	size_t const		w_size( sizeof(w) / sizeof(int) ); // number of elements in the array
	ints_t				withdrawals( w, w + w_size ); // initialize vector with array
	ints_t::iterator	wit_begin	= withdrawals.begin(); // iterator to the beginning of the vector
	ints_t::iterator	wit_end		= withdrawals.end(); // iterator to the end of the vector

	// Display initial account information
	Account::displayAccountsInfos(); // display the number of accounts, total amount, total number of deposits, and total number of withdrawals
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) ); // display the status of each account

	// Process deposits
	for ( acc_int_t it( acc_begin, dep_begin );
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeDeposit( *(it.second) ); 
	}

	// Display account information after deposits
	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	// Process withdrawals
	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
	}

	// Display account information after withdrawals
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
