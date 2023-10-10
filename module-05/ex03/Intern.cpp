/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:03:20 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/09 21:46:53 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {
	std::cout << GRNHB "[ Intern base constructor ]" reset << std::endl;
}

Intern::~Intern(void) {
	std::cout << REDHB "[ Intern destructor ]" reset << std::endl;
}

Intern::Intern(Intern const &i) {
	std::cout << GRNHB "[ Intern constructor ]" reset << std::endl;
	*this = i;
}

Intern &Intern::operator=(Intern const &i) {
	std::cout << YELHB "[ Intern copy constructor ]" reset << std::endl;
	(void)i;
	return *this;
}

const char *Intern::DoNotExitThisForm::what(void) const throw() {
	return (REDHB "This form name do not exist." reset);
}

AForm *Intern::makeForm(std::string form, std::string target) {
	AForm *f;
	std::pair<std::string, AForm *> forms[3];
	f = (form == "presidential pardon") ? reinterpret_cast<AForm *>(new PresidentialPardonForm(target)) : \
	(form == "robotomy request") ?  reinterpret_cast<AForm *>(new RobotomyRequestForm(target)) : \
	(form == "shrubbery creation") ? reinterpret_cast<AForm *>(new ShrubberyCreationForm(target)) : NULL;
	if (f == NULL) {
		throw Intern::DoNotExitThisForm();
	}
	std::cout << MAGHB "[ Intern creates " << *f << " ]" reset << std::endl;
	return (f);
}