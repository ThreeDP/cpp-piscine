/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:34:10 by dapaulin          #+#    #+#             */
/*   Updated: 2023/09/08 19:38:01 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"

Cat::Cat(void) : Animal(), brain(new Brain) {
	std::cout << "Default Cat constructor called" << std::endl;
	this->_type = "Cat";
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

Brain*	Cat::getBrain(void) const {
	return this->brain;
}

Cat::Cat(Cat const &cat) {
	std::cout << "Cat copy constructor called" << std::endl;
	Animal::_type = cat.getType();
	this->brain = new Brain(*(cat.getBrain()));
}

Cat	&Cat::operator=(Cat const &rhs) {
	std::cout << "Cat copy assigment operator called" << std::endl;
	if (this != &rhs) {
		Animal::_type = rhs.getType();
		this->brain = new Brain(*(rhs.getBrain()));
	}
	return *this;
}

void	Cat::makeSound(void) const {
	std::cout << "meow" << std::endl;
}