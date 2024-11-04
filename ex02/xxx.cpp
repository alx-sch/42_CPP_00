/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xxx.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:54:20 by aschenk           #+#    #+#             */
/*   Updated: 2024/11/01 21:07:58 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>		// for std::time_t, std::time, std::localtime, std::strftime
#include "Account.hpp"

/**
Gets the current 
*/
static std::time_t	getCurrentTime()
{
	std::time_t	now;

	std::time(&now);	// Get current time in seconds since epoch
	now += 3600;		// Adjust for UTC+1 (3600s = 1h)

	return (now);
}

/**
Opens a log file with a timestamped filename in the format "YYYYMMDD_HHMMSS.log".

The log file is opened only once during the program's execution, ensuring that
subsequent calls to this function return the same output file stream.

 @return `std::ofstream&`: 	A reference to the output file stream for writing to the log file.
*/
static std::ofstream&	openLogFile() // std::ofstream is a class to write on files
{
	static std::ofstream	logFile;				// static variable -> retains value between function calls
	static bool 			initialized = false;	// static: prevents the file from being opened multiple times
	std::time_t				currentTime;
	char					filename[20];			// 20 chars needed for the filename: YYYYMMDD_HHMMSS.log (19) + '\0'

	if (!initialized)
	{
		currentTime = getCurrentTime();

		// std::strftime is used to format date and time information into a string.
		// check `man strftime` for info on specifiers
		// std::localtime converts the time_t value to a tm struct representing the local time
		std::strftime(filename, sizeof(filename), "%Y%m%d_%H%M%S.log", std::localtime(&currentTime));
		logFile.open(filename);
		initialized = true;
	}

	return (logFile);
}

/**
Logs the current timestamp in the format "[YYYYMMDD_HHMMSS] " to the log file.
*/
void	Account::_displayTimestamp()
{
	std::time_t	now;
	char		timestamp[18];	// 18 chars needed for the timestamp: [YYYYMMDD_HHMMSS] (17) + '\0'

	now = getCurrentTime();
	std::strftime(timestamp, sizeof(timestamp), "[%Y%m%d_%H%M%S] ", std::localtime(&now));
	openLogFile() << timestamp;	// Write timestamp to log file
}

// Initialize static variables of the `Account` class
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts++),
										_amount(initial_deposit),
										_nbDeposits(0),
										_nbWithdrawals(0)
{
	initializeStatics(); // Ensure static variables are initialized
	_totalAmount += initial_deposit;
	_displayTimestamp();
	openLogFile() << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}