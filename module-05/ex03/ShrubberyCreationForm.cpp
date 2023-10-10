/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:40:30 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/09 20:53:20 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("shrubbery creation form", 145, 137), _target("Arthur Dent") {
	std::cout << GRNHB "[ ShrubberyCreationForm base constructor ]" reset << std::endl;
	std::cout << BLUHB << *this << reset << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("shrubbery creation form", 145, 137), _target(target) {
	std::cout << GRNHB "[ ShrubberyCreationForm constructor ]" reset << std::endl;
	std::cout << BLUHB << *this << reset << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << REDHB "[ ShrubberyCreationForm destructor ]" reset << std::endl;
	std::cout << BLUHB << *this << reset << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &scf) : AForm(scf) {
	std::cout << YELHB "[ ShrubberyCreationForm copy constructor ]" reset << std::endl;
	this->_target = scf._target;
	std::cout << BLUHB << *this << reset << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &scf) {
	std::cout << *this << std::endl;
	reinterpret_cast<AForm &>(*this) = scf;
	this->_target = scf._target;
	std::cout << MAGHB "[ ShrubberyCreationForm copy constructor assigment ]" reset << std::endl;
	std::cout << BLUHB << *this << reset << std::endl;
	return *this;
}

void ShrubberyCreationForm::_execute(void) const {
	std::ofstream	ofs;
	ofs.open((this->_target + "_shrubbery").c_str(), std::ifstream::out);
	if (!ofs) {
		throw ShrubberyCreationForm::FileError();
	}
	ofs << __TREE__;
	ofs.close();
}

const char *ShrubberyCreationForm::FileError::what(void) const throw() {
	return (REDHB "Error in file.\n" reset);
}