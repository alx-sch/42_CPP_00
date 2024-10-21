/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:49:34 by aschenk           #+#    #+#             */
/*   Updated: 2024/10/21 20:15:23 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
# define CONTACTS_HPP

# include <iostream>
# include <iomanip>
# include <sstream>

# define INIT_PROMPT "\x1b[32m the awsome PhoneBook \033[0m\n"
# define PROMPT "\x1b[33mPlease entre your command\033[0m\n  \x1b[32m[ADD] [SEARCH] [EXIT]\033[0m\n"
# define ERR_CMD "\x1b[31m 🚫 error command not found 🚫 \033[0m\n"
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