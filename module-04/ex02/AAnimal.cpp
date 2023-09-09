/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:18:35 by dapaulin          #+#    #+#             */
/*   Updated: 2023/09/09 16:24:47 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("") {
	std::cout << "Default AAnimal constructor called" << std::endl;
}

AAnimal::~AAnimal(void) {
	std::cout << "AAnimal Destructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &animal) {
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = animal;
}

AAnimal &AAnimal::operator=(AAnimal const &rhs) {
	std::cout << "AAnimal copy assigment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
	return *this;
}

std::string AAnimal::getType(void) const {
	return this->_type;
}
