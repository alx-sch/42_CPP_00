/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:49:38 by aschenk           #+#    #+#             */
/*   Updated: 2024/11/01 12:41:40 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "main.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();

		void	addContact();			// Add a contact to the phonebook
		void	showContacts() const;	// Show contacts in the phonebook

	private:
		int			_nrContacts;		// Number of contacts in the phonebook
		Contacts	_contacts[8];		// Array of contacts
};

#endif
