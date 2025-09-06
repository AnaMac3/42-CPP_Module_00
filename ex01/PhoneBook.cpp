/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:44:57 by amacarul          #+#    #+#             */
/*   Updated: 2025/09/06 16:08:59 by amacarul         ###   ########.fr       */
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

//---------------------------------------------------------------------------//
//FUNCIONES AUXILIARES/PRIVADAS
std::string	PhoneBook::_truncate(const std::string& str, std::size_t width)
{
	if (str.length() > width)
		return str.substr(0, width - 1) + "."; 
	return (str);
}

//----------------------------------------------------------------------//

//función add
void	PhoneBook::add(void)
{
	std::string fname, lname, nick, phone, secret;

	std::cout << "Enter first name: ";
	std::getline(std::cin, fname); //stdin::cin -> entrada estadar de c++, donde el programa lee datos del usuario desde el teclado

	std::cout << "Enter last name: ";
	std::getline(std::cin, lname);

	std::cout << "Enter Nickname: ";
	std::getline(std::cin, nick);

	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, phone);

	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin, secret);

	
	//gestionar que si se han superado los 8 contactos, reemplace el más antiguo
	int index = _index % 8;

	_contacts[index].fname = fname;
	_contacts[index].lname = lname;
	_contacts[index].nick = nick;
	_contacts[index].phone = phone;
	_contacts[index].secret = secret;
	_contacts[index].index = index + 1;

	_index ++;

	std::cout << "Contact added at index " << _contacts[index].index << " ✅" << std::endl;
}

//función search
void	PhoneBook::search(void)
{
	if (_index == 0)
	{
		std::cout << "PhoneBook is empty. Add some contacts first." << std::endl;
		return ;
	}
	//imprimir lista de contactos (MIRAR FORMATO)
	//cabecera
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << "|" << std::endl;
	
	//mostrar cada contacto
	//_index < 8 ? _index : 8 -> 
	for (int i = 0; i < (_index < 8 ? _index : 8); i++)
	{
		std::cout << std::setw(10) << _contacts[i].index << "|"
				  << std::setw(10) << _truncate(_contacts[i].fname, 10) << "|"
				  << std::setw(10) << _truncate(_contacts[i].lname, 10) << "|"
				  << std::setw(10) << _truncate(_contacts[i].nick, 10) << "|" << std::endl;
	}
	
	std::string input;
	std::cout << "Enter the contact index you want to search: ";
	std::getline(std::cin, input);

	//validar si es numero
	//validar que es un valor entre 1 y 8
	std::istringstream ss(input); //convierte el input en número de forma segura
	int	index;
	if (!(ss >> index) || index < 1 || index > 8 || index > _index)
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	//convertir indice 0-7 en 1-8
	int	realIndex = (index - 1) % 8; 
	//convertir index a int para poder comparar con _contacts[index] no?
	//int	i = std::stoi(input);
	//si pide un index que no hay o no es un número, mensaje error
	
	//devolver la infor de ese contacto
	std::cout << "First Name: " << _contacts[realIndex].fname << std::endl;
	std::cout << "Last Name: " << _contacts[realIndex].lname << std::endl;
	std::cout << "Nickname: " << _contacts[realIndex].nick << std::endl;
	std::cout << "Phone Number: " << _contacts[realIndex].phone << std::endl;
	std::cout << "Darkest Secret: " << _contacts[realIndex].secret << std::endl;
}

