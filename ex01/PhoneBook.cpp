/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:44:57 by amacarul          #+#    #+#             */
/*   Updated: 2025/09/06 15:02:24 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
//otros includes

/*array de contactos
puede almacenar 8 contactos
si se intenta meter un noveno, sustituye el más antiguo
no dynamic allocation
*/


//class declaration
PhoneBook::PhoneBook(void): _index(0) //inicialización de atributo en constructor, llama a una lista de inicialización,
									//más eficiente que llamar dentro del cuerpoo del constructor
									//por qué no hace falta inicializar aquí contacts, como el index?
									//Contact tiene un constructor por defecto, asi que C++ lo llama automáticamente
									//para cada uno. Cuando se construye PhoneBook, c++ automaticamente construye 8 objetos contact dentro del array,
									//int no tiene constructor por defecto
{
	
}

//destructor
PhoneBook::~PhoneBook(void)
{
    
}

//función add
void	PhoneBook::add(void)
{
	std::string fname, lname, nick;

	std::cout << "Enter first name: ";
	std::getline(std::cin, lname); //stdin::cin -> entrada estadar de c++, donde el programa lee datos del usuario desde el teclado

	std::cout << "Enter last name: ";
	std::getline(std::cin, lname);

	std::cout << "Enter Nickname: ";
	std::getline(std::cin, nick);

	//gestionar que si se han superado los 8 contactos, reemplace el más antiguo
	int index = _index % 8;

	_contacts[index].fname = fname;
	_contacts[index].lname = lname;
	_contacts[index].nick = nick;
	_contacts[index].index = index + 1;

	_index ++;

	std::cout << "Contact added at index " << _contacts[index].index << " ✅" << std::endl;
}

//función search
void	PhoneBook::search(void)
{
	if (_index = 0)
	{
		std::cout << "PhoneBook is empty. Add some contacts first." << std::endl;
		return ;
	}
	//imprimir lista de contactos (MIRAR FORMATO)
	
	
	std::string input;
	std::cout << "Enter the contact index you want to search: " << std::endl;
	std::getline(std::cin, input);

	//validar si es numero
	//validar que es un valor entre 1 y 8
	
	//convertir index a int para poder comparar con _contacts[index] no?
	int	i = std::stoi(input);
	//si pide un index que no hay o no es un número, mensaje error
	
	//devolver la infor de ese contacto
	std::cout << "First Name: ";
	std::cout << _contacts[i].fname << std::endl;
	std::cout << "Last Name: ";
	std::cout << _contacts[i].lname << std::endl;
	std::cout << "Nickname: ";
	std::cout << _contacts[i].nick << std::endl;
}

//función search
void	PhoneBook::print(void)
{
		
}

