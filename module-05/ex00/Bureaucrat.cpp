/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:46:53 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/03 23:38:56 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Serjinho"), _grade(150) {
	std::cout << GRNHB "Construct Bureaucrat" << Bureaucrat::_name;
	std::cout << " Grade with " << Bureaucrat::_grade << reset << std::endl;
}

Bureaucrat::Bureaucrat(std::string n, int g) : _name(n) {
	Bureaucrat::_setGrade(g);
	std::cout << GRNHB "Construct Bureaucrat" << Bureaucrat::_name;
	std::cout << " Grade with " << Bureaucrat::_grade << reset << std::endl;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << REDHB "Destruct Bureaucrat " << Bureaucrat::_name;
	std::cout << " Grade with " << Bureaucrat::_grade << reset << std::endl;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b) {
	os << HMAG << b.getName() << reset ", bureaucrat grade " HGRN << b.getGrade() << "." reset << std::endl;
	return (os);
}

const std::string Bureaucrat::getName(void) const {
	return this->_name;
}

int	Bureaucrat::getGrade(void) const {
	return this->_grade;
}

void Bureaucrat::_setGrade(int g) {
	if (g < Bureaucrat::_min) {
		throw Bureaucrat::GradeTooHighException();
	}
	else if (g > Bureaucrat::_max) {
		throw Bureaucrat::GradeTooLowException();
	}
	Bureaucrat::_grade = g;
}

void Bureaucrat::levelUp(void) {
	Bureaucrat::_setGrade(Bureaucrat::_grade - 1);
	std::cout << *this;
}

void Bureaucrat::levelDown(void) {
	Bureaucrat::_setGrade(Bureaucrat::_grade + 1);
	std::cout << *this;
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw() {
	return (BLUHB "Calm down, this isn't heaven! It has a limit." reset);
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw() {
	return (REDHB "But you don't need to scold the poor guy either." reset);
}