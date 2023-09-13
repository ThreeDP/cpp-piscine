/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:02:54 by dapaulin          #+#    #+#             */
/*   Updated: 2023/09/13 19:05:09 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"

Dog::Dog(void) : Animal(), brain(new Brain) {
	this->_type = "Dog";
	std::cout << GRNHB "[ Dog - Create a " BBLK << Animal::_type << BLK GRNHB " ]" reset << std::endl;
}

Dog::~Dog(void) {
	std::cout << REDHB "[ Dog - Destroy a " BBLK << Animal::_type << BLK REDHB " ]" reset << std::endl;
	delete this->brain;
}

Brain*	Dog::getBrain(void) const {
	return this->brain;
}

Dog::Dog(Dog const &dog) {
	Animal::_type = dog.getType();
	this->brain = new Brain(*(dog.getBrain()));
	std::cout << YELHB"[ Dog - Constructor copy " BBLK << Animal::_type << BLK YELHB " ]" reset << std::endl;
	std::cout << CYNHB "[ Copy < " BBLK << &*(dog.getBrain()) << BLK CYNHB " > to < " BBLK << &this->brain << BLK CYNHB " > ]" reset << std::endl;
}

Dog::Dog(Animal const *dog) {
	*this = *(dynamic_cast<const Dog*>(dog));
	std::cout << YELHB"[ Dog - Constructor copy " BBLK << Animal::_type << BLK YELHB " ]" reset << std::endl;
}

Dog	&Dog::operator=(Dog const &rhs) {
	if (this != &rhs) {
		Animal::_type = rhs.getType();
		this->brain = new Brain(*(rhs.getBrain()));
		std::cout << MAGHB "[ Dog - Copy < " BBLK << rhs.getBrain() << BLK MAGHB " > to < " BBLK << this->brain << BLK MAGHB " > ]" reset << std::endl;
	}
	std::cout << MAGHB "[ Dog - Constructor assigment " BBLK << Animal::_type << BLK MAGHB " ]" reset << std::endl;
	return *this;
}

void	Dog::makeSound(void) const {
	std::cout << BYEL "bark that I'm going through -:)" reset << std::endl;
}

void	Dog::showBrain(void) const {
	this->brain->printIdeas();
}