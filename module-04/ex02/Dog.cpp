/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:02:54 by dapaulin          #+#    #+#             */
/*   Updated: 2023/09/09 16:28:31 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"

Dog::Dog(void) : AAnimal(), brain(new Brain) {
	std::cout << "Default Dog constructor called" << std::endl;
	this->_type = "Dog";
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

Brain*	Dog::getBrain(void) const {
	return this->brain;
}

Dog::Dog(Dog const &dog) {
	std::cout << "Dog copy constructor called" << std::endl;
	AAnimal::_type = dog.getType();
	this->brain = new Brain(*(dog.getBrain()));
}

Dog	&Dog::operator=(Dog const &rhs) {
	std::cout << "Dog copy assigment operator called" << std::endl;
	if (this != &rhs) {
		AAnimal::_type = rhs.getType();
		this->brain = new Brain(*(rhs.getBrain()));
	}
	return *this;
}

void	Dog::makeSound(void) {
	std::cout << "bark that I'm going through" << std::endl;
}