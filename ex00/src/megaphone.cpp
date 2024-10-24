/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:43:27 by aschenk           #+#    #+#             */
/*   Updated: 2024/10/21 19:09:29 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // for std::cout
#include <cctype>   // for toupper

/**
Converts a character to uppercase and prints it.

 @param x 	The character to convert and print.
*/
static void shout(char x)
{
	std::cout << (char)toupper(x);
}

/**
The entry point of the program.

If no arguments are provided, it outputs a default message.
If arguments are provided, it converts each character of each argument to
uppercase and prints them to the standard output.

 @param argc 	The number of command-line arguments (including the program name).
 @param argv 	An array of C-style strings representing the command-line arguments.

 @return 		`0` upon successful execution.
*/
int main(int argc, char **argv)
{
	int		i;
	size_t	j;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (i = 1; i < argc; i++)
		{
			std::string str(argv[i]);
			for (j = 0; j < str.length(); j++)
				shout(str[j]);
		}
		std::cout << std::endl;
	}
	return (0);
}
