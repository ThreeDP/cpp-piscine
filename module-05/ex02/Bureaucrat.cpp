/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:46:53 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/09 05:56:34 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Serjinho"), _grade(150) {
	std::cout << GRNHB "Construct Bureaucrat " << Bureaucrat::_name;
	std::cout << " Grade with " << Bureaucrat::_grade << reset << std::endl;
}

Bureaucrat::Bureaucrat(std::string n, int g) : _name(n) {
	Bureaucrat::_setGrade(g);
	std::cout << GRNHB "Construct Bureaucrat " << Bureaucrat::_name;
	std::cout << " Grade with " << Bureaucrat::_grade << reset << std::endl;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << REDHB "Destruct Bureaucrat " << Bureaucrat::_name;
	std::cout << " Grade with " << Bureaucrat::_grade << reset << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &b) {
	*this = b;
	std::cout << YELHB "Constructor copy" reset << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
	if (this != &rhs) {
		const_cast<std::string &>(this->_name) = rhs.getName();
		this->_grade = rhs.getGrade();
	}
	std::cout << MAGHB "Constructor assigment" reset << std::endl;
	return *this;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b) {
	os << HMAG << b.getName() << reset ", bureaucrat grade " HGRN << b.getGrade() << "." reset;
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

void	Bureaucrat::signAForm(AForm &f) {
	if (f.getSign() == true) {
		std::cout << *this << " couldn’t sign " << f << " because is already signed." << std::endl;
		return ;
	}
	if (Bureaucrat::_grade <= f.getGradeSign()) {
		f.beSigned(*this);
		std::cout << *this << " signed " << f << std::endl;
	} else {
		std::cout << *this << " couldn’t sign " << f << " because he is noob." << std::endl; 
	}
}

void	Bureaucrat::executeForm(AForm const & form) {
	form.execute(*this);
	std::cout << *this << " executed " << form << std::endl;
}