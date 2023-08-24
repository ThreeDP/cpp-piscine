/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:24:06 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/24 20:34:15 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
	std::cout << "FragTrap Constructor Called" << std::endl;
	this->_hit = 100;
	this->_energy = 100;
	this->_damage = 30;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
	std::cout << "FragTrap Constructor Called" << std::endl;
	this->_hit = 100;
	this->_energy = 100;
	this->_damage = 30;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap Destructor Called" << std::endl;
}

FragTrap::FragTrap(FragTrap const & ct) {
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = ct;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs) {
	std::cout << "FragTrap Copy assigment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hit = rhs.getHit();
		this->_energy = rhs.getEnergy();
		this->_damage = rhs.getDamage();
	}
	return *this;
}

void	FragTrap::attack(const std::string &target) {
	if (this->_hit < 1 || this->_energy < 1)
		return ;
	std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_damage << " points of damage!" << std::endl;
	this->_energy--;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "High five guys!" << std::endl;
}
