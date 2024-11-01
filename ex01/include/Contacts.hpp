/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:49:34 by aschenk           #+#    #+#             */
/*   Updated: 2024/11/01 15:35:48 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
# define CONTACTS_HPP

# include "main.hpp"

class	Contacts
{
	public:

		Contacts();
		~Contacts();

		void	addContact();							// Add a contact
		void	printContactOverview(int index) const;	// Print an overview for this contact
		void	printContactAll() const;				// Print details for this contact

	private:
	
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
};

#endif
