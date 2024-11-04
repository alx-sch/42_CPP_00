/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:49:48 by aschenk           #+#    #+#             */
/*   Updated: 2024/11/04 18:18:11 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(void)
{
	PhoneBook		Phonebook;
	std::string 	input;

	std::cout << TITLE << std::endl;

	while (true)
	{
		std::cout << std::endl << PROMPT << std::endl;

		std::getline(std::cin, input);

		// Check for EOF in user input (CTRL + D)
		if (std::cin.eof())
		{
			exitEOF();
		}

		// Check user input
		else if (input == "ADD")
		{
			Phonebook.addContact();
		}
		else if (input == "SEARCH")
		{
			Phonebook.showContacts();
		}
		else if (input == "EXIT")
		{
			std::cout << BYE << std::endl;
			break ;
		}
		else
		{
			std::cout << ERR_NOT_FOUND << std::endl;
		}
	}

	return 0;
}
