/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:49:48 by aschenk           #+#    #+#             */
/*   Updated: 2024/10/23 12:56:29 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.hpp"
#include "PhoneBook.hpp"
#include "Contacts.hpp"

#include <cstring>  // for strcmp
#include <limits>  // For std::numeric_limits

/**
Checks if the end-of-file (EOF) condition has been reached during user input.

 If EOF is detected:
 - The function clears the EOF state using `std::cin.clear()`.
 - It discards any remaining characters in the input buffer up to the next newline ('\n')
 *   using `std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')`.
 * - It displays a message indicating that EOF has been detected.
 *
 * @return `true` if EOF has been detected; otherwise, `false`.
 */
bool is_eof_detected() {
    if (std::cin.eof()) { // Check if EOF has been set
        std::cout << "Exiting." << std::endl;
		std::cout << EXIT;
        std::cin.clear(); // Clear the EOF state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard remaining input
        return true; // Indicate that EOF was detected
    }
    return false; // Indicate that EOF was not detected
}

/**
Checks if user input exceeded the specified maximum length.

If the input is too long (failbit is set):
 - 	The function clears the failbit using `std::cin.clear()`.
 - 	It then discards any remaining characters in the input buffer up to the next newline ('\n')
	using `std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\\n')`.
 -	It displays an error message indicating the maximum allowable input length and returns `0`.

 @param max_input 	The maximum allowable number of characters for input (including the null terminator).

 @return			`0` if the input is too long;
 					`1` if the input length is valid.
 */
int	is_input_too_long(int max_input)
{
	if (std::cin.fail()) // failbit will be set if more than MAX_INPUT characters are entered
	{
		std::cin.clear();  // Clear the failbit
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard remaining characters using largest value for I/O operations
		std::cout << ERR_TOO_L RED BOLD << (max_input - 1) << " chars) ❌" RESET << std::endl;
		return (0);
	}
	return (1);
}

int main(void)
{
	char			input[MAX_INPUT];
	PhoneBook		Phone;
	Contacts		Contact;
	std::string 	test;

	std::cout << TITLE;
	while(1)
	{
		std::cout << std::endl;
		std::cout << PROMPT;

		std::cin.getline(input, MAX_INPUT);

		if (std::cin.eof()) // Check for EOF
		{
			std::cout << "EXIT" << std::endl;
			std::cout << EXIT;
			break;
		}

		if (!is_input_too_long(MAX_INPUT)) // Check if the input was too long
			continue ;  // Skip the rest of the loop and ask for input again

		else if (strcmp(input, "ADD") == 0)
			Phone.add_data();
		else if (strcmp(input, "SEARCH") == 0)
			Phone.PrintAllData();
		else if (strcmp(input, "EXIT") == 0)
		{
			std::cout << EXIT;
			break;
		}
		else
			std::cout << ERR_NOT_FOUND;
	}
	return (0);
}
