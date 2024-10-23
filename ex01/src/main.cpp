/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:49:48 by aschenk           #+#    #+#             */
/*   Updated: 2024/10/22 18:55:52 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contacts.hpp"

#include <cstring>  // for strcmp

int main(void)
{
	char		command[MAX_INPUT_L];
	PhoneBook	Phone;
	Contacts	Contact;
	std::string test;

	std::cout << TITLE;
	while(1)
	{
		std::cout << PROMPT;
		std::cin.getline(command, MAX_INPUT_L);


        // Check if the input was too long
        if (std::cin.fail())  // failbit will be set if more than MAX_INPUT_L characters are entered
        {
            std::cin.clear();  // Clear the failbit
            std::cin.ignore(10000, '\n');  // Discard remaining characters using a large value
            std::cout << "Error: Input too long. Please enter a command with less than "
                      << (MAX_INPUT_L - 1) << " characters." << std::endl;
            continue;  // Skip the rest of the loop and ask for input again
        }


		if (command[0] == '\0')
		{
			std::cout << CNTR_D;
			exit(1);
		}
		else if (strcmp(command, "ADD") == 0)
			Phone.add_data();
		else if (strcmp(command, "SEARCH") == 0)
			Phone.PrintAllData();
		else if (strcmp(command, "EXIT") == 0)
		{
			std::cout << DONE;
			break;
		}
		else
			std::cout << ERR_CMD;
	}
	return 0;
}