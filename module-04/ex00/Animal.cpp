/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:18:35 by dapaulin          #+#    #+#             */
/*   Updated: 2023/09/05 19:20:04 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("") {
	std::cout << "Default Animal constructor called" << std::endl;
}

Animal::~Animal(void) {
	std::cout << "Animal Destructor called" << std::endl;
}

Animal::Animal(Animal const &animal) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = animal;
}

Animal &Animal::operator=(Animal const &rhs) {
	std::cout << "Animal copy assigment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
	return *this;
}

std::string Animal::getType(void) const {
	return this->_type;
}

void	Animal::makeSound(void) const {
	std::cout << "sniff sniff" << std::endl;
}