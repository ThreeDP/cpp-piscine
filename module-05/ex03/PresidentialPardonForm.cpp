/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:40:30 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/05 17:14:35 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("presidential pardon form", 25, 5), _target("Zaphod Beebleblox") {
	std::cout << GRNHB "[ PresidentialPardonForm base constructor ]" reset << std::endl;
	std::cout << BLUHB << *this << reset << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("presidential pardon form", 25, 5), _target(target) {
	std::cout << GRNHB "[ PresidentialPardonForm constructor ]" reset << std::endl;
	std::cout << BLUHB << *this << reset << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << REDHB "[ PresidentialPardonForm destructor ]" reset << std::endl;
	std::cout << BLUHB << *this << reset << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ppf) : AForm(ppf) {
	std::cout << YELHB "[ PresidentialPardonForm copy constructor ]" reset << std::endl;
	this->_target = ppf._target;
	std::cout << BLUHB << *this << reset << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &ppf) {
	std::cout << *this << std::endl;
	reinterpret_cast<AForm &>(*this) = ppf;
	this->_target = ppf._target;
	std::cout << MAGHB "[ PresidentialPardonForm copy constructor assigment ]" reset << std::endl;
	std::cout << BLUHB << *this << reset << std::endl;
	return *this;
}

void PresidentialPardonForm::_execute(void) const {
	std::cout << this->_target << " has been pardoned by Zaphod Beebleblox." << std::endl;
}