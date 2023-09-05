/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:34:10 by dapaulin          #+#    #+#             */
/*   Updated: 2023/09/05 19:49:07 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"

Cat::Cat(void) : Animal() {
	std::cout << "Default Cat constructor called" << std::endl;
	this->_type = "Cat";
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(Cat const &cat) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = cat;
}

Cat	&Cat::operator=(Cat const &rhs) {
	std::cout << "Cat copy assigment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
	return *this;
}

void	Cat::makeSound(void) const {
	std::cout << "meow" << std::endl;
}