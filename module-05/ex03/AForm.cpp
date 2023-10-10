/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 00:04:09 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/09 20:52:35 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("blank paper"), _sign(false), _grade_to_sign(1), _grade_to_exec(1) {
	std::cout << GRNHB "[ Base AForm Constructor " << AForm::_name << " ]" reset << std::endl;
}

AForm::AForm(std::string n, int sign, int exec) : _name(n), _sign(false), _grade_to_sign(1), _grade_to_exec(1) {
	AForm::_setGradeToExec(exec);
	AForm::_setGradeToSign(sign);
	std::cout << GRNHB "[ AForm Constructor " << AForm::_name << " ]" reset << std::endl;
}

AForm::~AForm(void) {
	std::cout << REDHB "[ AForm Destructor " << AForm::_name << " ]" reset << std::endl;
}

AForm::AForm(const AForm &f) : _name(f.getName()), _sign(f.getSign()), _grade_to_sign(f.getGradeSign()), _grade_to_exec(f.getGradeExec()) {
	std::cout << YELHB "[ AForm Copy Constructor " << AForm::_name << " ]" reset << std::endl;
}

AForm &AForm::operator=(const AForm &f) {
	if (this != &f) {
		const_cast<std::string &>(this->_name) = f.getName();
		AForm::_setGradeToExec(f.getGradeExec());
		AForm::_setGradeToSign(f.getGradeSign());
		this->_sign = f.getSign();
	}
	std::cout << YELHB "[ AForm Assigment Constructor " << AForm::_name << " ]" reset << std::endl;
	return *this;
}

void	AForm::_validRange(int r) {
	if (r > AForm::_min) {
		throw AForm::GradeTooLowException();
	} else if (r < AForm::_max) {
		throw AForm::GradeTooHighException();
	}
}

void	AForm::_setGradeToExec(int e) {
	AForm::_validRange(e);
	const_cast<int &>(this->_grade_to_exec) = e;
}

void	AForm::_setGradeToSign(int s) {
	AForm::_validRange(s);
	const_cast<int &>(this->_grade_to_sign) = s;
}

std::string AForm::getName(void) const {
	return AForm::_name;
}

int AForm::getGradeExec(void) const {
	return AForm::_grade_to_exec;
}

int AForm::getGradeSign(void) const {
	return AForm::_grade_to_sign;
}

bool AForm::getSign(void) const {
	return AForm::_sign;
}

std::ostream &operator<<(std::ostream &os, AForm const &f) {
	os << YELHB "AForm: " << f.getName() << " | Signed: " << f.getSign() << " | Grade to Sign: " << f.getGradeSign() << " | Grade to Exec: " << f.getGradeExec() << reset;
	return (os);
}

void AForm::beSigned(const Bureaucrat &b) {
	if (b.getGrade() <= AForm::_grade_to_sign) {
		AForm::_sign = true;
		return ;
	}
	throw AForm::GradeTooLowException();
}

void AForm::execute(const Bureaucrat &b) const {
	if (b.getGrade() <= AForm::getGradeExec()) {
		if (AForm::isSigned() == true) {
			this->_execute();
			return ;
		}
		throw AForm::IsNotSigned();
	}
	throw AForm::GradeTooLowException();
}

bool AForm::isSigned(void) const {
	if (AForm::_sign) {
		return (1);
	}
	return (0);
}

const char *AForm::IsNotSigned::what(void) const throw() {
	return (BLUHB "f: It was not possible to execute this form, it is not signed." reset);
}


const char *AForm::GradeTooHighException::what(void) const throw() {
	return (BLUHB "f: Calm down, this isn't heaven! It has a limit." reset);
}

const char *AForm::GradeTooLowException::what(void) const throw() {
	return (REDHB "f: But you don't need to scold the poor guy either." reset);
}