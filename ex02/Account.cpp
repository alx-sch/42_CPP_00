/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:43:27 by aschenk           #+#    #+#             */
/*   Updated: 2024/11/01 16:40:56 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>

// Function to get the log file stream
std::ofstream& getLogFile() {
    static std::ofstream logFile;
    static bool initialized = false;

    if (!initialized) {
        // Get current time
        std::time_t now = std::time(nullptr);
        now += 3600; // Adjust for UTC+1
        char buf[20];
        std::strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S.log", std::localtime(&now));
        logFile.open(buf);
        initialized = true;
    }

    return logFile;
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Utility function to log output with a timestamp
void Account::_displayTimestamp() {
    // Get current time
    std::time_t now = std::time(nullptr);
    now += 3600; // Adjust for UTC+1
    char buf[20];
    std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", std::localtime(&now));
    getLogFile() << buf;
}

// Static function to display account info
void Account::displayAccountsInfos() {
    _displayTimestamp();
    getLogFile() << "accounts:" << _nbAccounts
                 << ";total:" << _totalAmount
                 << ";deposits:" << _totalNbDeposits
                 << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

// Constructor
Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts++), _amount(initial_deposit),
      _nbDeposits(0), _nbWithdrawals(0) {
    _totalAmount += initial_deposit;

    _displayTimestamp();
    getLogFile() << "index:" << _accountIndex
                 << ";amount:" << _amount << ";created" << std::endl;
}

// Destructor
Account::~Account() {
    _displayTimestamp();
    getLogFile() << "index:" << _accountIndex
                 << ";amount:" << _amount << ";closed" << std::endl;
}

// Function to make a deposit
void Account::makeDeposit(int deposit) {
    _amount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;

    _displayTimestamp();
    getLogFile() << "index:" << _accountIndex
                 << ";p_amount:" << _amount - deposit
                 << ";deposit:" << deposit
                 << ";amount:" << _amount
                 << ";nb_deposits:" << _nbDeposits << std::endl;
}

// Function to make a withdrawal
bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    getLogFile() << "index:" << _accountIndex
                 << ";p_amount:" << _amount;

    if (_amount >= withdrawal) {
        _amount -= withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        _totalAmount -= withdrawal;

        getLogFile() << ";withdrawal:" << withdrawal
                     << ";amount:" << _amount
                     << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        return true;
    } else {
        getLogFile() << ";withdrawal:refused" << std::endl;
        return false;
    }
}

// Function to check the account amount
int Account::checkAmount() const {
    return _amount;
}

// Function to display account status
void Account::displayStatus() const {
    _displayTimestamp();
    getLogFile() << "index:" << _accountIndex
                 << ";amount:" << _amount
                 << ";deposits:" << _nbDeposits
                 << ";withdrawals:" << _nbWithdrawals << std::endl;
}
