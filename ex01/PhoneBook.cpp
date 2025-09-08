/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:44:57 by amacarul          #+#    #+#             */
/*   Updated: 2025/09/08 11:58:14 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

//------------------------CONSTRUCTOR                   ------------------------
PhoneBook::PhoneBook(void): _totalContacts(0)
{
	//_contacts array is automatically initialized
	//C++ calls the default constructor of Contacts for each element
}

//------------------------DESTRUCTOR                    ------------------------
PhoneBook::~PhoneBook(void)
{
    //nothing to clean up manually
	//C++ automatically calls destructors for each Contact in the array
}

//------------------------PRIVATE HELPER FUNCTIONS      ------------------------

//Prompt the user for a string until it is not empty
std::string PhoneBook::_getNonEmptyInput(const std::string& prompt)
{
	std::string input;
	while (input.empty())
	{
		std::cout << prompt;
		std::getline(std::cin, input); //read a full line from standard input

		if (input.empty())
			std::cout << "Mandatory field. Please enter a value." << std::endl;
	}
	return (input);
}

//Print the table header for contact display
void	PhoneBook::_printTableHeader(void)
{
	//std::setw(n) sets the width of the next output
	//Helps align columns for a neat table
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << "|" << std::endl;
}

//Truncate strings longer than width with a dot
std::string	PhoneBook::_truncate(const std::string& str, std::size_t width)
{
	if (str.length() > width)
		return str.substr(0, width - 1) + "."; 
	return (str);
}

//Print a single row in the contact table
void	PhoneBook::_printContactRow(const Contact& c)
{
	std::cout << std::setw(10) << c.index << "|"
			  << std::setw(10) << _truncate(c.fname, 10) << "|"
			  << std::setw(10) << _truncate(c.lname, 10) << "|"
			  << std::setw(10) << _truncate(c.nick, 10) << "|" << std::endl;
}

//Ask the user for a valid contact index. Returns -1 if input is invalid
int	PhoneBook::_getValidIndex(int validContactsCount)
{
	std::string input;
	std::cout << "Enter the contact index you want to search: ";
	std::getline(std::cin, input);

	std::istringstream ss(input); //std::istringstream converts to int safely
	int	index;
	
	//Validate input: must be a number within range [1, validContactsCount]
	if (!(ss >> index) || !(ss.eof()) || index < 1 || index > validContactsCount)
	{
		std::cout << "Invalid index." << std::endl;
		return (-1);
	}
	return (index);
}

//Print all details of a contact
void	PhoneBook::_printFullContact(const Contact& c)
{
	std::cout << "First Name: " << c.fname << std::endl;
	std::cout << "Last Name: " << c.lname << std::endl;
	std::cout << "Nickname: " << c.nick << std::endl;
	std::cout << "Phone Number: " << c.phone << std::endl;
	std::cout << "Darkest Secret: " << c.secret << std::endl;
}

//------------------------PUBLIC FUNCTIONS    		    ------------------------

void	PhoneBook::add(void)
{
	//Prompt user for all fields, cannot be empty
	std::string fname = _getNonEmptyInput("Enter First Name: ");
	std::string lname = _getNonEmptyInput("Enter Last Name: ");
	std::string nick = _getNonEmptyInput("Enter Nickname: ");
	std::string phone = _getNonEmptyInput("Enter Phone Number: ");
	std::string secret = _getNonEmptyInput("Enter Darkest Secret: ");

	//Circular buffer: overwrite oldes contact if more than 8
	int arrayIndex = _totalContacts % 8;

	//Safe contact
	_contacts[arrayIndex].fname = fname;
	_contacts[arrayIndex].lname = lname;
	_contacts[arrayIndex].nick = nick;
	_contacts[arrayIndex].phone = phone;
	_contacts[arrayIndex].secret = secret;
	_contacts[arrayIndex].index = arrayIndex + 1; //Displayed index: 1-8

	_totalContacts ++;

	std::cout << "Contact added at index " << _contacts[arrayIndex].index 
			  << " ✅" << std::endl;
}

void	PhoneBook::search(void)
{
	//Exit if no contacts exist
	if (_totalContacts == 0)
	{
		std::cout << "PhoneBook is empty. Add some contacts first." 
				  << std::endl;
		return ;
	}
	
	//Print table header
	_printTableHeader();

	//Print each stored contact (max 8)
	int validContactsCount = (_totalContacts < 8 ? _totalContacts : 8);
	for (int i = 0; i < validContactsCount; i++)
		_printContactRow(_contacts[i]);
	
	//Ask user for an index
	int index = _getValidIndex(validContactsCount);
	if (index == -1)
		return ;
	
	//Convert to array position [0 - 7]
	int	arrayIndex = (index - 1) % 8; 
	
	//Print full contact information
	_printFullContact(_contacts[arrayIndex]);
}

