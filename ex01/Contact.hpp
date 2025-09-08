/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:41:57 by amacarul          #+#    #+#             */
/*   Updated: 2025/09/08 11:10:18 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string> //std::string

class Contact {
	public:
		//-----------------------CONSTRUCTOR/DESTRUCTOR  -----------------------
		Contact(); //Constructor: initializes a new contact
		~Contact(); //Destructor
		
		//-----------------------PUBLIC ATRIBUTES        -----------------------
		int	index;			//Contact index (1-8) 
		std::string fname;	//First name
		std::string lname;	//Last name
		std::string nick;	//Nickname
		std::string phone;	//Phone number
		std::string secret;	//Darkest secret
};

#endif