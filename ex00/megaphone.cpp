/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:13:23 by amacarul          #+#    #+#             */
/*   Updated: 2025/09/05 16:15:08 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	int i;
	int j;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (i = 1; i < argc; i++)
		{
			for(j = 0; argv[i][j]; j++)
				std::cout << (char) std::toupper(argv[i][j]);
			std::cout << " ";
		}
	}
	std::cout << std::endl;
	return (0);
}