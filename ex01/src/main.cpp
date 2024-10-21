/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:49:48 by aschenk           #+#    #+#             */
/*   Updated: 2024/10/21 20:20:03 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contacts.hpp"

int main(void)
{
	std::string	command;
	PhoneBook	Phone;
	Contacts	Contact;
	std::string test;

	std::cout << INIT_PROMPT;
	while(1)
	{
		std::cout << PROMPT;
		std::getline (std::cin,command);
		if (command[0] == '\0')
		{
			std::cout << CNTR_D;
			exit(1);
		}
		else if (command == "ADD")
			Phone.add_data();
		else if (command == "SEARCH")
			Phone.PrintAllData();
		else if (command == "EXIT")
		{
			std::cout << DONE;
			break;
		}
		else
			std::cout << ERR_CMD;
	}
	return 0;
}