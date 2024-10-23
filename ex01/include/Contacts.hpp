/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:49:34 by aschenk           #+#    #+#             */
/*   Updated: 2024/10/22 18:57:13 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
# define CONTACTS_HPP

# include <iostream>
# include <iomanip>
# include <sstream>

# define MAX_INPUT_L	16

// Define ANSI escape codes for colors and styles
# define RESET			"\033[0m"
# define BOLD			"\033[1m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define RED			"\033[91m"
# define ORANGE			"\033[38;5;208m"
# define BLUE 			"\033[34m"
# define VIOLET 		"\033[35;1m"

#define TITLE			BOLD ORANGE	"┌─────────────────────────┐\n" \
									"│  ☎️ My Tiny Phonebook ☎️  │\n" \
									"└─────────────────────────┘\n\n" RESET
# define PROMPT			YELLOW "Please enter a command:\n" GREEN "[ADD]  [SEARCH]  [EXIT]\n" RESET
# define ERR_CMD		RED BOLD "❌ Command not found ❌\n" RESET
# define DONE "\x1b[32m Thank you for using our awsome PhoneBook \033[0m\n"
# define INDEX_TO_DISPLAY "\x1b[33mPlease entre your Contact index\033[0m\n"
# define PIPE "\x1b[32m|\033[0m"
# define PHONEBOOK_EMPTY "\x1b[31m 🚫 No Contact was Add 🚫 \033[0m\n"
# define NO_INDEX "\x1b[31m 🚫 index not found 🚫 \033[0m\n"
# define ADD_PROCCES "\x1b[32mADD\033[0m"
# define INDEX_TABLE "\x1b[32m  Index   |  F_name  |  L_name  | Nickname \033[0m\n\n"
# define EMPTY_FIELD "\x1b[31m 🚫 Empty Field 🚫 \033[0m\n"
# define CNTR_D "\x1b[31m Exit \033[0m\n"

class	Contacts
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
	public:
		void	add_contact(Contacts *contact);
		void	printContacts(Contacts contact, int index);
		void	printContact(Contacts contact);
};

void	log_trunc(const std::string& str);

#endif