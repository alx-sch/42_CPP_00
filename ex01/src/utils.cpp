/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:00:51 by aschenk           #+#    #+#             */
/*   Updated: 2024/10/29 17:35:59 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

/**
Exits the program gracefully when an end-of-file (EOF) condition is detected in
user input (CTRL + D).
*/
void	exitEOF()
{
	std::cout << std::endl << "Exiting." << std::endl;
	std::cout << BYE << std::endl;
	exit(0);
}

/**
Truncates the input string to 10 chars, if need be, and prints the string,
right-aligned with a width of 10 chars.

 @param str 	The string to be truncated and printed.
*/
void truncAndPrint(const std::string& str)
{
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".";	// Print the first 9 chars followed by a dot
	else
		std::cout << std::setw(10) << str;		// Print entire string right-aligned with width of 10 chars.
}
