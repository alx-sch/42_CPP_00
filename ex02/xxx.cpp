/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xxx.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:54:20 by aschenk           #+#    #+#             */
/*   Updated: 2024/11/01 16:42:07 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>		// for std::time_t, std::time, std::localtime, std::strftime
#include "Account.hpp"


/**
Opens a log file with a timestamped filename in the format "YYYYMMDD_HHMMSS.log".

 @return std::ofstream 	An output file stream for writing to the timestamped log file.
*/
static std::ofstream&	openLogFile() // std::ofstream is a class to write on files
{
	static std::ofstream	logFile;
	static bool 			initialized = false;
	std::time_t				currentTime;;
	char					filename[20];	// 20 chars needed for the filename: YYYYMMDD_HHMMSS.log (19) + '\0'

	std::time(&currentTime);	// Get current time in seconds since epoch
	currentTime += 3600;		// Adjust for UTC+1 (3600s = 1h)

	// std::strftime is used to format date and time information into a string.
	// check `man strftime` for info on speficifiers
	// std::localtime converts the time_t value to a tm struct representing the local time
	std::strftime(filename, sizeof(filename), "%Y%m%d_%H%M%S.log", std::localtime(&currentTime));

	return (std::ofstream(filename));
}
