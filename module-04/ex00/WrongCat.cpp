/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:36:28 by dapaulin          #+#    #+#             */
/*   Updated: 2023/09/05 19:48:28 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal() {
	std::cout << "Default WrongCat constructor called" << std::endl;
	this->_type = "Crab";
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &wrongcat) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = wrongcat;
}

WrongCat	&WrongCat::operator=(WrongCat const &rhs) {
	std::cout << "WrongCat copy assigment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
	return *this;
}

void	WrongCat::makeSound(void) const {
	std::cout << "Click! Click!" << std::endl;
}