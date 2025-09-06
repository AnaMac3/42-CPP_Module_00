/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:44:25 by amacarul          #+#    #+#             */
/*   Updated: 2025/09/06 16:14:08 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//definir estructura de la clase: variables(atributos), funciones(métodos) e interfac(pública/privada)
//solo se ponen las declaraciones, qué tiene la clase, no el código completo de los métodos

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream> //std::cin, std::cout, std::endl
# include <string> //std::string
# include <sstream> //std::istringstream, std::ostringstream
# include <iomanip> //std::setw, std::setfill, std::setprecision

class PhoneBook {
	private:
		//lo que solo se vaya a usar dentro
		Contact _contacts[8];
		int		_index;
		
		std::string _truncate(const std::string& str, std::size_t width);
	
	public: 
		//lo que se vaya a usar fuera del código de la clase

		//acciones que tiene que tener:
		//add
		//search

		//algún tipo de enlace a Contact no?

		PhoneBook();
		~PhoneBook();
		void	add();
		void	search();
		void	print();
	
};

#endif