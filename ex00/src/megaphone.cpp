/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:43:27 by aschenk           #+#    #+#             */
/*   Updated: 2024/10/21 12:40:21 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SHOUT(x) std::cout << (char)toupper(x);

int main(int argc, char **argv)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < ac; i++)
		{
			std::string str(av[i]);
			for (size_t j = 0; j < str.length(); j++)
				LOG(str[j]);
		}
		std::cout << std::endl;
    }
    return (0);
}
