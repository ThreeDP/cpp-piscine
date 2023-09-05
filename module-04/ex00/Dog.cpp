/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:02:54 by dapaulin          #+#    #+#             */
/*   Updated: 2023/09/05 19:49:24 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"

Dog::Dog(void) : Animal() {
	std::cout << "Default Dog constructor called" << std::endl;
	this->_type = "Dog";
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(Dog const &dog) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = dog;
}

Dog	&Dog::operator=(Dog const &rhs) {
	std::cout << "Dog copy assigment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
	return *this;
}

void	Dog::makeSound(void) const {
	std::cout << "bark that I'm going through" << std::endl;
}