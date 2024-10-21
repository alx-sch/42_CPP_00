/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:49:38 by aschenk           #+#    #+#             */
/*   Updated: 2024/10/21 20:01:22 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contacts.hpp"
# include <stdlib.h>
# include <string>



class PhoneBook
{
	public:
		PhoneBook()
		{
			number_of_contact = 0;
		}
		void	add_data();
		bool	SearchContact();
		void	PrintAllData();

	private:
		Contacts	contacts[8];
		int			number_of_contact;
};

#endif