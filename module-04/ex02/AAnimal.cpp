/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:18:35 by dapaulin          #+#    #+#             */
/*   Updated: 2023/09/13 21:25:32 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("") {
	std::cout << GRNHB "[ AAnimal - Create a " BBLK << AAnimal::_type << BLK GRNHB " ]" reset << std::endl;
}

AAnimal::~AAnimal(void) {
	std::cout << REDHB "[ AAnimal - Destroy a " BBLK << AAnimal::_type << BLK REDHB " ]" reset << std::endl;
}

AAnimal::AAnimal(AAnimal const &animal) {
	*this = animal;
	std::cout << YELHB"[ AAnimal - Constructor copy " BBLK << AAnimal::_type << BLK YELHB " ]" reset << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &rhs) {
	if (this != &rhs) {
		this->_type = rhs.getType();
	}
	std::cout << MAGHB "[ Animal - Constructor assigment " BBLK << AAnimal::_type << BLK MAGHB " ]" reset << std::endl;
	return *this;
}

std::string AAnimal::getType(void) const {
	return this->_type;
}