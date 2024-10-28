/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:01:16 by aschenk           #+#    #+#             */
/*   Updated: 2024/10/28 21:39:05 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h> // for exit(), atoi()

# include <iostream> // for std::cout, std::cin
# include <iomanip> // for std:setw
# include <sstream> // std::ostringstream

# include "config.hpp"
# include "PhoneBook.hpp"
# include "Contacts.hpp"

// utils.cpp

void	exitEOF();
void	truncAndPrint(const std::string& str);
