/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:19:51 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/18 16:56:48 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(void) {
	this->gun = NULL;
	return ;
}

HumanB::HumanB(std::string name) {
	this->name = name;
	return ;
}

HumanB::~HumanB(void) {
	return ;
}

void	HumanB::setWeapon(Weapon &gun) {
	this->gun = &gun;
}

void	HumanB::attack(void) {
	std::cout << this->name << " with their " << this->gun->getType() << std::endl;
}