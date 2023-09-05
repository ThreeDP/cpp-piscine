/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:31:15 by dapaulin          #+#    #+#             */
/*   Updated: 2023/09/05 19:48:44 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("Gopher") {
	std::cout << "Default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &wrongAnimal) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = wrongAnimal;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs) {
	std::cout << "WrongAnimal copy assigment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
	return *this;
}

std::string WrongAnimal::getType(void) const {
	return this->_type;
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "Squeeek!" << std::endl;
}