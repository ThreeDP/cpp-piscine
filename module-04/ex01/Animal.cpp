/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:18:35 by dapaulin          #+#    #+#             */
/*   Updated: 2023/09/13 16:47:59 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Animal") {
	std::cout << GRNHB "[ Animal - Create a " BBLK << Animal::_type << BLK GRNHB " ]" reset << std::endl;
}

Animal::~Animal(void) {
	std::cout << REDHB "[ Animal - Destroy a " BBLK << Animal::_type << BLK REDHB " ]" reset << std::endl;
}

Animal::Animal(Animal const &animal) {
	*this = animal;
	std::cout << YELHB"[ Animal - Constructor copy " BBLK << Animal::_type << BLK YELHB " ]" reset << std::endl;
}

Animal& Animal::operator=(const Animal &rhs) {
	if (this != &rhs) {
		this->_type = rhs.getType();
	}
	std::cout << MAGHB "[ Animal - Constructor assigment " BBLK << Animal::_type << BLK MAGHB " ]" reset << std::endl;
	return *this;
}

std::string Animal::getType(void) const {
	return this->_type;
}

void	Animal::makeSound(void) const {
	std::cout << BYEL "sniff sniff -:)" reset << std::endl;
}

void	Animal::showBrain(void) const {
	std::cout << "Do nothing!" << std::endl;
}