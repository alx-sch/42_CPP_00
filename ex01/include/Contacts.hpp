/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:49:34 by aschenk           #+#    #+#             */
/*   Updated: 2024/10/29 17:32:26 by aschenk          ###   ########.fr       */
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

		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;
};

void	log_trunc(const std::string& str);

#endif
