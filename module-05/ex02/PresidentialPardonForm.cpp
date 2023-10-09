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

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("white paper", 25, 5) {
	std::cout << GRNHB "[ PresidentialPardonForm base constructor ]" reset << std::endl;
	std::cout << *this << std::endl;
	std::cout << BLUHB << *this << reset << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5) {
	std::cout << GRNHB "[ PresidentialPardonForm constructor ]" reset << std::endl;
	std::cout << *this << std::endl;
	std::cout << BLUHB << *this << reset << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << REDHB "[ PresidentialPardonForm destructor ]" reset << std::endl;
	std::cout << *this << std::endl;
	std::cout << BLUHB << *this << reset << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &scf) : AForm(scf) {
	std::cout << YELHB "[ PresidentialPardonForm copy constructor ]" reset << std::endl;
	std::cout << *this << std::endl;
	std::cout << BLUHB << *this << reset << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &scf) {
	std::cout << *this << std::endl;
	reinterpret_cast<AForm &>(*this) = scf;
	std::cout << MAGHB "[ PresidentialPardonForm copy constructor assigment ]" reset << std::endl;
	std::cout << BLUHB << *this << reset << std::endl;
	return *this;
}

void PresidentialPardonForm::_execute(const Bureaucrat &b) const {
	std::cout << b << " has been pardoned by Zaphod Beebleblox." << std::endl;
}