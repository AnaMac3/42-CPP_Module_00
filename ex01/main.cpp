/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:52:40 by amacarul          #+#    #+#             */
/*   Updated: 2025/09/10 10:50:33 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

/**
* @brief	Entry point of the program.
*			This function acts as the user interface for the phonebook app.
*			It handles user input and calls the appropriate PhoneBook methods.
*			Possible user commands:
*			- ADD: Prompts the user to add a new contact. Delegates the logic
*			to PhoneBook::add()
*			- SEARCH: Displays a summary table of stored contacts. Then asks
*			the user to enter an index and displays the full contact details.
*			Delegates the logic to PhoneBook::search().
*			- EXIT: Exits the program gracefully
*			
*/

int	main(void)
{
	PhoneBook myPhoneBook;
	std::string command;

	std::cout << "Welcome to your PhoneBook!" << std::endl;
	std::cout << "Choose the action: ADD, SEARCH, EXIT" << std::endl;

	while (true)
	{
		std::cout << "> ";
		std::getline(std::cin, command);

		if (std::cin.eof())
		{
			std::cout << "\nEOF detected. Exiting ..." << std::endl;
			break ;
		}
		if (command == "ADD")
			myPhoneBook.add();
		else if (command == "SEARCH")
			myPhoneBook.search();
		else if (command == "EXIT")
		{
			std::cout << "See you soon!" << std::endl;
			break ;
		}
		else
		{
			std::cout << "Invalid command. Try again." << std::endl;
		}	
	}
	return (0);
}
