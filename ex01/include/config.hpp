/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:43:03 by aschenk           #+#    #+#             */
/*   Updated: 2024/10/23 12:43:13 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_HPP
# define CONFIG_HPP

# define MAX_INPUT		16

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
									"└─────────────────────────┘\n" RESET
# define PROMPT			YELLOW "Please enter:\n" GREEN "[ADD]  [SEARCH]  [EXIT]\n" RESET
# define ERR_NOT_FOUND	RED BOLD "❌ Option not found ❌\n" RESET
# define ERR_TOO_L		RED BOLD "❌ Input too long (max. " RESET
# define EXIT		 	ORANGE BOLD "Thank you for using My Tiny Phonebook\n" RESET
# define INDEX_TO_DISPLAY "\x1b[33mPlease entre your Contact index\033[0m\n"
# define PIPE "\x1b[32m|\033[0m"
# define PHONEBOOK_EMPTY "\x1b[31m 🚫 No Contact was Add 🚫 \033[0m\n"
# define NO_INDEX "\x1b[31m 🚫 index not found 🚫 \033[0m\n"
# define ADD_PROCCES "\x1b[32mADD\033[0m"
# define INDEX_TABLE "\x1b[32m  Index   |  F_name  |  L_name  | Nickname \033[0m\n\n"
# define EMPTY_FIELD "\x1b[31m 🚫 Empty Field 🚫 \033[0m\n"
# define CNTR_D "\x1b[31m Exit \033[0m\n"

#endif
