/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:43:03 by aschenk           #+#    #+#             */
/*   Updated: 2024/10/28 21:46:19 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_HPP
# define CONFIG_HPP

# define MAX_INPUT		32

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
									"└─────────────────────────┘" RESET
# define PROMPT			YELLOW "Please enter:\n" GREEN "[ADD]  [SEARCH]  [EXIT]" RESET
# define ERR_NOT_FOUND	RED BOLD "❌ Option not found ❌" RESET
# define ERR_TOO_L		RED BOLD "❌ Input too long (max. " RESET
# define BYE		 	ORANGE BOLD "Thank you for using My Tiny Phonebook" RESET

// SEARCH

# define IDX_TABLE		GREEN "|     Index|    F_Name|    L_Name|  Nickname|" RESET
# define NO_CONTACTS 	YELLOW BOLD "📒 Phonebook is empty! No contacts added yet." RESET
# define SEL_CONTACT_1	YELLOW "Select contact (index): " RESET
# define SEL_CONTACT	YELLOW "Select contact (1-" RESET
# define INV_IDX		RED BOLD "❌ Invalid index (press Enter to leave) ❌" RESET


# define PIPE "\x1b[32m|\033[0m"

# define ADD_PROCCES "\x1b[32mADD\033[0m"
# define EMPTY_FIELD "\x1b[31m 🚫 Empty Field 🚫 \033[0m\n"
# define CNTR_D "\x1b[31m Exit \033[0m\n"

#endif
