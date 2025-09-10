/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:44:57 by amacarul          #+#    #+#             */
/*   Updated: 2025/09/10 10:40:11 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

//------------------------CONSTRUCTOR                   ------------------------
/**
* @brief	Construct a new PhoneBook with no contacts.
*/

PhoneBook::PhoneBook(void): _totalContacts(0)
{
	
}

//------------------------DESTRUCTOR                    ------------------------
/**
* @brief	Destroy the PhoneBook.
*/

PhoneBook::~PhoneBook(void)
{
    
}

//------------------------PRIVATE HELPER FUNCTIONS      ------------------------

/**
* @brief	Asks the user for a string until it is not empty.
*			- Uses std::getline() to read an entire line of text from the stdin
*			until a newline is found. 
*			- If the string is empty, prints an error message and repeats the
*			loop. The loop continues until the input is not empty.
*
* @param prompt	Message shown to the user.
* @return std::string	A Non-empty string entered by the user.
*/

std::string PhoneBook::_getNonEmptyInput(const std::string& prompt)
{
	std::string input;

	while (input.empty())
	{
		std::cout << prompt;
		std::getline(std::cin, input);

		if (input.empty())
			std::cout << "Mandatory field. Please enter a value." << std::endl;
	}
	return (input);
}

/**
* @brief	Print the table header for contact display.
* 			- std::setw(n) sets the width of the next output
*			
*/

void	PhoneBook::_printTableHeader(void)
{
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << "|" << std::endl;
}

/**
* @brief	Truncate strings longer than width and append a dot.
*
* @param str	The original string
* @param width	The maximum allowed width
* @return	A truncated string (with a dot if truncated).
*/

std::string	PhoneBook::_truncate(const std::string& str, std::size_t width)
{
	if (str.length() > width)
		return str.substr(0, width - 1) + "."; 
	return (str);
}

/**
* @brief	Print a single row (summary) of a contact.
*
* @param c	The contact to display.
*/

void	PhoneBook::_printContactRow(const Contact& c)
{
	std::cout << std::setw(10) << c.index << "|"
			  << std::setw(10) << _truncate(c.fname, 10) << "|"
			  << std::setw(10) << _truncate(c.lname, 10) << "|"
			  << std::setw(10) << _truncate(c.nick, 10) << "|" << std::endl;
}

/**
* @brief	Ask the user for a valid contact index.
*			- std::getline(): reads a whole line from the user into a string
*			- std::istringstream ss(): creates a string stream from the user
*			input. This allows us to safely attempt to convert the string
*			into a integer without crashing if the input is not numeric.
*			- Checks if the input is a number in the valid range
*				* ss >> index: tries to extract an integer from the string
*				stream. If it fails, the operation returns false.
*				* ss.eof(): checks if the entire input string has been consumed.
*				This prevents partial inputs like "12abc" from being accepted.
*				* Range chek: ensures the index is between 1 and 
*				validContactsCount
*			- If is not in the valid range, prints an error msg and returns -1 
*			- Returns the index
*
* @param validContactsCount	Number of contacts currently stored
* @return	The index (1-validContactsCount) or -1 if invalid.
*/

int	PhoneBook::_getValidIndex(int validContactsCount)
{
	std::string input;
	std::cout << "Enter the contact index you want to search: ";
	std::getline(std::cin, input);

	std::istringstream ss(input);
	int	index;
	
	if (!(ss >> index) || !(ss.eof()) || index < 1 || index > validContactsCount)
	{
		std::cout << "Invalid index." << std::endl;
		return (-1);
	}
	return (index);
}

/**
* @brief	Print all details of a given contact.
*
* @param c	The contact to display.
*/

void	PhoneBook::_printFullContact(const Contact& c)
{
	std::cout << "First Name: " << c.fname << std::endl;
	std::cout << "Last Name: " << c.lname << std::endl;
	std::cout << "Nickname: " << c.nick << std::endl;
	std::cout << "Phone Number: " << c.phone << std::endl;
	std::cout << "Darkest Secret: " << c.secret << std::endl;
}

//------------------------PUBLIC METHODS    		    ------------------------

/**
* @brief	Add a new contact (overwrites oldest if full).
*			- Prompt user for Contact fields
*			- Computes arrayIndex using circular buffer logic to overwrite
*			oldest contact if needed
*			- Assign all entered fields to the corresponding Contact object
*			- Set the contact's display index (1-8) for easier reference
*			- Increments _totalContacts to keep track of total number of
*			added contacts
*
*/

void	PhoneBook::add(void)
{
	std::string fname = _getNonEmptyInput("Enter First Name: ");
	std::string lname = _getNonEmptyInput("Enter Last Name: ");
	std::string nick = _getNonEmptyInput("Enter Nickname: ");
	std::string phone = _getNonEmptyInput("Enter Phone Number: ");
	std::string secret = _getNonEmptyInput("Enter Darkest Secret: ");

	int arrayIndex = _totalContacts % 8;

	_contacts[arrayIndex].fname = fname;
	_contacts[arrayIndex].lname = lname;
	_contacts[arrayIndex].nick = nick;
	_contacts[arrayIndex].phone = phone;
	_contacts[arrayIndex].secret = secret;
	_contacts[arrayIndex].index = arrayIndex + 1;

	_totalContacts ++;

	std::cout << "Contact added at index " << _contacts[arrayIndex].index 
			  << " ✅" << std::endl;
}

/**
* @brief	Search and display a contact by index.
*			- Checks if any contacts exists. If none, prints a message and
*			returns
*			- Prints the table header (_printTableHeader())
*			- Prints each stored contact's summary row (_printContactRow())
*			up to a maximum of 8 
*			- Asks the user to enter a contact index using _getValdiIndex()
*			- If the input is invalid (-1), exits the function
*			- Converts the 1-based displayed index to the 0-based array position
*			- Prints the full contact details (_printFullContact()) for the 
*			selected contact
*
*/

void	PhoneBook::search(void)
{
	if (_totalContacts == 0)
	{
		std::cout << "PhoneBook is empty. Add some contacts first." 
				  << std::endl;
		return ;
	}
	
	_printTableHeader();

	int validContactsCount = (_totalContacts < 8 ? _totalContacts : 8);
	for (int i = 0; i < validContactsCount; i++)
		_printContactRow(_contacts[i]);
	
	int index = _getValidIndex(validContactsCount);
	if (index == -1)
		return ;
	
	int	arrayIndex = (index - 1) % 8; 
	
	_printFullContact(_contacts[arrayIndex]);
}

