/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:49:42 by aschenk           #+#    #+#             */
/*   Updated: 2024/10/23 11:45:03 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contacts.hpp"

#include "config.hpp"

/**
 * @brief Truncates the input string to 10 characters and prints it.
 *
 * If the string is longer than 10 characters, it will print the first
 * 9 characters followed by a dot. If the string is shorter or equal to
 * 10 characters, it will print the string as is, right-aligned.
 *
 * @param str The string to be truncated and printed.
 */
void log_trunc(const std::string& str)
{
    if (str.length() > 10)
        std::cout << str.substr(0, 9) << ".";
    else
        std::cout << std::setw(10) << str;
}


void	Contacts::printContacts(Contacts contact, int index)
{
	std::ostringstream oss;

	oss << (index + 1);
	log_trunc(oss.str());
	std::cout << PIPE;
	log_trunc(contact.first_name);
	std::cout << PIPE;
	log_trunc(contact.last_name);
	std::cout << PIPE;
	log_trunc(contact.nickname);
	std::cout << std::endl;
}

void	Contacts::printContact(Contacts contact)
{
	std::cout << "First name: " << contact.first_name << std::endl;
	std::cout << "Last name: " << contact.last_name << std::endl;
	std::cout << "Nickname: " << contact.nickname << std::endl;
	std::cout << "Phone number: " << contact.phone_number << std::endl;
	std::cout << "Darkest secret: " << contact.darkest_secret << std::endl;
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

void	Contacts::add_contact(Contacts *contact)
{
	std::string	input;
	PhoneBook	Phone;

	(*contact).first_name = data_no_null("   [First name]   > ");
	(*contact).last_name = data_no_null("    [Last name]   > ");
	(*contact).nickname = data_no_null("    [Nickname]    > ");
	(*contact).phone_number = data_no_null("  [Phone number]  > ");
	(*contact).darkest_secret = data_no_null(" [Darkest secret] > ");
}
