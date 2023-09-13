/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:07:23 by dapaulin          #+#    #+#             */
/*   Updated: 2023/09/13 18:50:27 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iomanip>

Brain::Brain(void) : _ideas(), _size(0) {
	std::cout << GRNHB "[ Brain - Create a " BBLK "Brain" << BLK GRNHB " ]" reset << std::endl;
}

Brain::~Brain(void) {
	std::cout << REDHB "[ Brain - Destroy a " BBLK "Brain" << BLK REDHB " ]" reset << std::endl;
}

Brain::Brain(Brain const &brain) {
	std::cout << CYNHB "[ Brain - Constructor copy < " BBLK << &brain << BLK CYNHB " > ]" reset << std::endl;
	if (this != &brain) {
		*this = brain;
	}
}

Brain	&Brain::operator=(Brain const &rhs) {
	std::cout << MAGHB "[ Brain - Constructor assigment " BBLK "Brain" BLK MAGHB " ]" reset << std::endl;
	if (this != &rhs) {
		this->_size = rhs.getSize();
		for (int i = 0; i < this->_size; i++) {
			this->_ideas[i] = rhs.getIdea(i);
		}
	}
	return *this;
}

int	Brain::getSize(void) const {
	return this->_size;
}

std::string	Brain::getIdea(int i) const {
	if (i < __IDEAS_SIZE__ && i >= 0) {
		return (this->_ideas[i]);
	}
	return NULL;
}

void	Brain::setIdea(std::string idea) {
	if (this->_size < __IDEAS_SIZE__) {
		this->_ideas[this->_size] = idea;
		this->_size++;
	}
}

void	Brain::setIdeas(std::string *ideas, int size) {
	for (int i = 0; i < size; i++) {
		this->setIdea(ideas[i]);
	}
}

void	Brain::printIdeas(void) const {
	std::cout << std::endl;
	std::cout << BLUHB "| " << std::setw(47) << std::left << this << " |" reset << std::endl;
	for (int i = 0; i < this->_size ; i++) {
		std::cout << CYNHB "| " << std::right << std::setw(3) << i << " | ";
		std::cout << std::setw(41) << Brain::getIdea(i) << " |" reset << std::endl;
	}
	std::cout << CYNHB "|_________________________________________________|" reset << std::endl << std::endl;
}

