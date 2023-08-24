/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:39:52 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/24 18:59:21 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name(""), _hit(10), _energy(10), _damage(0) {
	std::cout << "ClapTrap Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hit(10), _energy(10), _damage(0) {
	std::cout << "ClapTrap Constructor Called" << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap Destructor Called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & ct) {
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = ct;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs) {
	std::cout << "ClapTrap Copy assigment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hit = rhs.getHit();
		this->_energy = rhs.getEnergy();
		this->_damage = rhs.getDamage();
	}
	return *this;
}

std::string ClapTrap::getName(void) const {
	return (this->_name);
}

unsigned int	ClapTrap::getHit(void) const {
	return (this->_hit);
}

unsigned int	ClapTrap::getEnergy(void) const {
	return (this->_energy);
}

unsigned int	ClapTrap::getDamage(void) const {
	return (this->_damage);
}

void	ClapTrap::attack(const std::string &target) {
	if (this->_hit < 1 || this->_energy < 1)
		return ;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_damage << " points of damage!" << std::endl;
	this->_energy--;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hit < 1)
		return ;
	std::cout << this->_name << " took " << amount << " damage " << std::endl;
	this->_hit -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hit < 1|| this->_energy < 1)
		return ;
	std::cout << this->_name << " Rapair " << amount << " of hit points" << std::endl;
	this->_hit += amount;
	this->_energy--;
}

void	ClapTrap::getStatus(void) const {
	std::cout << std::endl;
	std::cout << "Name: " << this->_name << std::endl;
	std::cout << "Life: " << this->_hit << std::endl;
	std::cout << "Energy: " << this->_energy << std::endl;
	std::cout << "Damage: " << this->_damage << std::endl;
	std::cout << std::endl;
}