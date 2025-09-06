/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:41:57 by amacarul          #+#    #+#             */
/*   Updated: 2025/09/06 15:45:42 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//definir estructura de la clase: variables(atributos), funciones(métodos) e interfac(pública/privada)
//solo se ponen las declaraciones, qué tiene la clase, no el código completo de los métodos

#ifndef CONTACT_HPP

# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact { //the class
	public: //Access specifier - 
	//lo que se vaya a usar fuera del código de la clase
	
	//index
	//first name
	//last name
	//nickname ??
		Contact(); //constructor declaration
		~Contact(); //destructor
		
		int	index; //esto igual es algo que se le tiene que dar desde fuera...
		std::string fname;
		std::string lname;
		std::string nick;
		std::string phone;
		std::string secret;

	private:
	//lo que solo se vaya a usar dentro
};

#endif