/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:50:05 by aschenk           #+#    #+#             */
/*   Updated: 2024/10/30 13:34:35 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
Implementation of the `PhoneBook` class, managing contact storage and display.
*/

#include "main.hpp"

PhoneBook::PhoneBook() : nrContacts(0) {}

PhoneBook::~PhoneBook() {}	// Empty / default

/**
Adds a new contact to the phonebook.
If the phonebook has space (up to 8 contacts), it stores the contact at the next available index.
If the phonebook is full, it overwrites the oldest entry.

 @note 	The available indices range from 0 to 7 in the implementation,
		but represent entries 1 to 8 in the phonebook.
 */
void	PhoneBook::addContact()
{
	int			index;

	index = this->nrContacts % 8;
	this->contacts[index].addContact();
	this->nrContacts++;

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
	int			indexSelect;
	std::string	input;

	// If there are no contacts added yet
	if (this->nrContacts == 0)
	{
		std::cout << IDX_TABLE << std::endl << std::endl;
		std::cout << NO_CONTACTS << std::endl;
		return ;
	}

	// Print list of contacts
	std::cout << IDX_TABLE << std::endl;
	index = 0;
	while(index < this->nrContacts && index < 8)
	{
		this->contacts[index].printContactOverview(index);
		index++;
	}
	std::cout << std::endl;

	// Contact selection / display
	while (true)
	{
		// Prompt user to select a contact
		if (this->nrContacts == 1)
		{
			std::cout << SEL_CONTACT_1;
		}
		else
		{
			std::cout << SEL_CONTACT << YELLOW << std::min(nrContacts, 8) << "): " RESET;
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
		indexSelect = atoi(input.c_str());  // Converts input to const char* and then to int
		indexSelect -= 1;
		if (indexSelect >= 0 && indexSelect < this->nrContacts && indexSelect < 8) // Valid selection
		{
			this->contacts[indexSelect].printContactAll();
			break ;
		}
		else // Invalid selection
			std::cout << INV_IDX << std::endl;
	}

	return ;
}
