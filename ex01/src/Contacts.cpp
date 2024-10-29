/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:49:42 by aschenk           #+#    #+#             */
/*   Updated: 2024/10/29 17:42:19 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Contacts::Contacts() {}		// Empty / default

Contacts::~Contacts() {}	// Empty / default

void	Contacts::printContactOverview(int index) const
{
	std::ostringstream oss; // Type of output stream that holds its data in a string buffer (Output String Stream)

	oss << (index + 1); // Conversion into a string format and stored in the internal buffer of oss
	truncAndPrint(oss.str());
	std::cout << PIPE;
	truncAndPrint(this->_first_name);
	std::cout << PIPE;
	truncAndPrint(this->_last_name);
	std::cout << PIPE;
	truncAndPrint(this->_nickname);
	std::cout << std::endl;
}

void	Contacts::printContactAll() const
{
	std::cout << "First name: " << this->_first_name << std::endl;
	std::cout << "Last name: " << this->_last_name << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone number: " << this->_phone_number << std::endl;
	std::cout << "Darkest secret: " << this->_darkest_secret << std::endl;
}

std::string	data_no_null(const char *prompt)
{
	std::string	line;
	while(1)
	{
		std::cout << ADD_PROCCES << prompt;
		std::getline (std::cin,line);
		if (line.length())
			return (line);
		if(line[0] == '\0')
		{
			std::cout << CNTR_D;
			exit(1);
		}
		std::cout << EMPTY_FIELD;
	}
}

void	Contacts::addContact()
{
	std::string	input;
	PhoneBook	Phone;

	this->_first_name = data_no_null("     [First name] > ");
	this->_last_name = data_no_null("      [Last name] > ");
	this->_nickname = data_no_null("       [Nickname] > ");
	this->_phone_number = data_no_null("   [Phone number] > ");
	this->_darkest_secret = data_no_null(" [Darkest secret] > ");
}
