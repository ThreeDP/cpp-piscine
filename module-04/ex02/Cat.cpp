/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:34:10 by dapaulin          #+#    #+#             */
/*   Updated: 2023/09/13 19:36:10 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"

Cat::Cat(void) : AAnimal(), brain(new Brain) {
	this->_type = "Cat";
	std::cout << GRNHB "[ Cat - Create a " BBLK << AAnimal::_type << BLK GRNHB " ]" reset << std::endl;
}

Cat::~Cat(void) {
	std::cout << REDHB "[ Cat - Destroy a " BBLK << AAnimal::_type << BLK REDHB " ]" reset << std::endl;
	delete this->brain;
}

Brain*	Cat::getBrain(void) const {
	return this->brain;
}

Cat::Cat(Cat const &cat) {
	AAnimal::_type = cat.getType();
	this->brain = new Brain(*(cat.getBrain()));
	std::cout << YELHB"[ Cat - Constructor copy " BBLK << AAnimal::_type << BLK YELHB " ]" reset << std::endl;
	std::cout << CYNHB "[ Copy < " BBLK << &*(cat.getBrain()) << BLK CYNHB " > to < " BBLK  << &this->brain << BLK CYNHB " > ]" reset << std::endl;
}

Cat::Cat(AAnimal const *cat) {
	*this = *(dynamic_cast<const Cat*>(cat));
	std::cout << YELHB"[ Cat - Constructor copy " BBLK << AAnimal::_type << BLK YELHB " ]" reset << std::endl;
}

Cat	&Cat::operator=(Cat const &rhs) {
	if (this != &rhs) {
		AAnimal::_type = rhs.getType();
		this->brain = new Brain(*(rhs.getBrain()));
		std::cout << MAGHB "[ Cat - Copy < " BBLK << rhs.getBrain() << BLK MAGHB " > to < " BBLK << this->brain << BLK MAGHB " > ]" reset << std::endl;
	}
	std::cout << MAGHB "[ Cat - Constructor assigment " BBLK << AAnimal::_type << BLK MAGHB " ]" reset << std::endl;
	return *this;
}

void	Cat::makeSound(void) const {
	std::cout << BYEL "meow -:)" reset << std::endl;
}

void	Cat::showBrain(void) const {
	this->brain->printIdeas();
}