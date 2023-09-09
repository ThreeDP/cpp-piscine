/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:07:23 by dapaulin          #+#    #+#             */
/*   Updated: 2023/09/08 19:42:55 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) : _ideas() {
	std::cout << "Default brain constructor called" << std::endl;
}

Brain::~Brain(void) {
	std::cout << "Default brain destructor called" << std::endl;
}

Brain::Brain(Brain const &brain) {
	std::cout << "Brain copy constructor called" << std::endl;
	if (this != &brain) {
		for (int i = 0; i < __IDEAS_SIZE__; i++) {
			this->_ideas[i] = brain.getIdea(i);
		}
	}
}

std::string	Brain::getIdea(int i) const {
	if (i < __IDEAS_SIZE__ && i >= 0) {
		return (this->_ideas[i]);
	}
	return NULL;
}

Brain	&Brain::operator=(Brain const &rhs) {
	std::cout << "Brain copy assigment operator called" << std::endl;
	if (this != &rhs) {
		for (int i = 0; i < __IDEAS_SIZE__; i++) {
			this->_ideas[i] = rhs.getIdea(i);
		}
	}
	return *this;
}

