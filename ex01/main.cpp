/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:52:40 by amacarul          #+#    #+#             */
/*   Updated: 2025/09/06 14:40:42 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
/*
posibles inputs del usuario:
ADD: guarda un nuevo contacto
SEARCH: te saca la lista de contactos guardados en cuatro columnas
(index, first name, last name, nickname) de 10 chars de ancho y con 
un pipe como separador, alineadas a la derecha. Si el texto es más
largo que la columna, el último char se reemplaza por un punto. Luego,
se le pide al usuario el indice del contacto que quiere, y se le
devuelve la infor del contacto
EXIT
*/

int	main(void)
{
	//tiene que leer el input del usuario (readline?)

	//si es ADD:
		//PhoneBook::add
	
	//si es SEARCH
		//PhoneBook::search

	//si es EXIT
		//exit
	

	//PRUEBA_1
	std::cout << "Prueba 1: " << std::endl;
	//crear un objeto de contact:
	Contact myObj;
	//acceder a sus atributos:
	myObj.fname = "Nombre";
	myObj.lname = "Apellido";
	myObj.nick = "Nick name";
	//devolver en stdout
	std::cout << myObj.fname << std::endl;
	std::cout << myObj.lname << std::endl;
	std::cout << myObj.nick << std::endl;

	//PRUEBA_2
	std::cout << "Prueba 2: " << std::endl;
	//crear objeto de PhoneBook
	PhoneBook myPhoneBook;
	std::string command;

	std::cout << "Welcome to your PhoneBook!" << std::endl;
	std::cout << "Choose the acction: ADD, SEARCH, EXIT" << std::endl;

	while (true)
	{
		std::cout << "> ";
		std::getline(std::cin, command);

		if (std::cin.eof())
		{
			std::cout << "\nEOF detected, Exiting ..." << std::endl; //no se si tiene que hacer esto
			break ;
		}
		if (command == "ADD")
			myPhoneBook.add();
		if (command == "SEARCH")
			myPhoneBook.search();
	}

	
	return (0);
}
