/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:49:48 by aschenk           #+#    #+#             */
/*   Updated: 2024/10/28 22:04:39 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(void)
{
	PhoneBook		Phonebook;
	Contacts		Contact;
	std::string 	input;
	std::string 	test;

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
			std::cout << ERR_NOT_FOUND << std::endl;
	}
	return (0);
}
