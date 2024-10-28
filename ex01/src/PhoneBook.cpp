/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:50:05 by aschenk           #+#    #+#             */
/*   Updated: 2024/10/28 22:28:43 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
Implementation of the PhoneBook class, managing contact storage and display..
*/

#include "main.hpp"

PhoneBook::PhoneBook() : nr_contacts(0) {}

PhoneBook::~PhoneBook() {} // Empty / default

/**
Adds a new contact to the phonebook.
Stores the contact at the next available index, overwriting the oldest entry if full.
*/
void	PhoneBook::addContact()
{
	int			index;

	index = this->nr_contacts % 8;
	this->contacts[index].addContact();
	this->nr_contacts++;

	return ;
}

/**
Displays the list of contacts in the phonebook.

This function shows an overview of contacts (up to 8) stored in the phonebook
and prompts the user to select one by entering the corresponding index number.

The function handles invalid input and selection, providing appropriate feedback
to the user.
*/
void	PhoneBook::showContacts() const
{
	int			index;
	int			index_select;
	std::string	input;

	// If there are no contacts added yet
	if (this->nr_contacts == 0)
	{
		std::cout << IDX_TABLE << std::endl << std::endl;
		std::cout << NO_CONTACTS << std::endl;
		return ;
	}

	// Print list of contacts
	std::cout << IDX_TABLE << std::endl;
	index = 0;
	while(index < this->nr_contacts && index < 8)
	{
		this->contacts[index].printContactOverview(index);
		index++;
	}
	std::cout << std::endl;

	// Contact selection / display
	while (true)
	{
		// Prompt user to select a contact
		if (this->nr_contacts == 1)
		{
			std::cout << SEL_CONTACT_1;
		}
		else
		{
			std::cout << SEL_CONTACT << YELLOW << std::min(nr_contacts, 8) << "): " RESET;
		}

		std::getline(std::cin, input);

		 // Check for EOF in user input (CTRL + D)
		if (std::cin.eof())
		{
			exitEOF();
		}

		// Check if input is empty (user pressed Enter without typing anything)
		if (input.empty())
		{
			break ;
		}

		// Process user input (index selection)
		index_select = atoi(input.c_str());  // Converts input to const char* and then to int
		index_select -= 1;
		if (index_select >= 0 && index_select < this->nr_contacts && index_select < 8) // Valid selection
		{
			this->contacts[index_select].printContactAll();
			break ;
		}
		else // Invalid selection
			std::cout << INV_IDX << std::endl;
	}

	return ;
}
