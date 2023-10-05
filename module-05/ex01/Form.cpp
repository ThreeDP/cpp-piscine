/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 00:04:09 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/05 12:54:56 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("blank paper"), _sign(false), _grade_to_sign(1), _grade_to_exec(1) {
	std::cout << GRNHB "[ Base Form Constructor " << Form::_name << " ]" reset << std::endl;
}

Form::Form(std::string n, int sign, int exec) : _name(n), _sign(false), _grade_to_sign(1), _grade_to_exec(1) {
	Form::_setGradeToExec(exec);
	Form::_setGradeToSign(sign);
	std::cout << GRNHB "[ Form Constructor " << Form::_name << " ]" reset << std::endl;
}

Form::~Form(void) {
	std::cout << REDHB "[ Form Destructor " << Form::_name << " ]" reset << std::endl;
}

Form::Form(const Form &f) : _name(f.getName()), _sign(f.getSign()), _grade_to_sign(f.getGradeSign()), _grade_to_exec(f.getGradeExec()) {
	std::cout << YELHB "[ Form Copy Constructor " << Form::_name << " ]" reset << std::endl;
}

Form &Form::operator=(const Form &f) {
	if (this != &f) {
		const_cast<std::string &>(this->_name) = f.getName();
		Form::_setGradeToExec(f.getGradeExec());
		Form::_setGradeToSign(f.getGradeSign());
		this->_sign = f.getSign();
	}
	std::cout << YELHB "[ Form Assigment Constructor " << Form::_name << " ]" reset << std::endl;
	return *this;
}

void	Form::_validRange(int r) {
	if (r > Form::_min) {
		throw Form::GradeTooLowException();
	} else if (r < Form::_max) {
		throw Form::GradeTooHighException();
	}
}

void	Form::_setGradeToExec(int e) {
	Form::_validRange(e);
	const_cast<int &>(this->_grade_to_exec) = e;
}

void	Form::_setGradeToSign(int s) {
	Form::_validRange(s);
	const_cast<int &>(this->_grade_to_exec) = s;
}

std::string Form::getName(void) const {
	return Form::_name;
}

int Form::getGradeExec(void) const {
	return Form::_grade_to_exec;
}

int Form::getGradeSign(void) const {
	return Form::_grade_to_sign;
}

bool Form::getSign(void) const {
	return Form::_sign;
}

std::ostream &operator<<(std::ostream &os, Form const &f) {
	os << YELHB "Form: " << f.getName() << " | Signed: " << f.getSign() << " | Grade to Sign: " << f.getGradeSign() << " | Grade to Exec: " << f.getGradeExec() << reset;
	return (os);
}

void Form::beSigned(const Bureaucrat &b) {
	if (b.getGrade() <= Form::_grade_to_sign) {
		Form::_sign = true;
		return ;
	}
	throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what(void) const throw() {
	return (BLUHB "f: Calm down, this isn't heaven! It has a limit." reset);
}

const char *Form::GradeTooLowException::what(void) const throw() {
	return (REDHB "f: But you don't need to scold the poor guy either." reset);
}