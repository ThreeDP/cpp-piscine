/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:40:30 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/05 17:14:35 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("robotomy request form", 72, 45), _target("Marvin") {
	std::cout << GRNHB "[ RobotomyRequestForm base constructor ]" reset << std::endl;
	std::cout << BLUHB << *this << reset << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("robotomy request form", 72, 45), _target(target) {
	std::cout << GRNHB "[ RobotomyRequestForm constructor ]" reset << std::endl;
	std::cout << BLUHB << *this << reset << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << REDHB "[ RobotomyRequestForm destructor ]" reset << std::endl;
	std::cout << BLUHB << *this << reset << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rrf) : AForm(rrf) {
	std::cout << YELHB "[ RobotomyRequestForm copy constructor ]" reset << std::endl;
	this->_target = rrf._target;
	std::cout << BLUHB << *this << reset << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rrf) {
	std::cout << *this << std::endl;
	reinterpret_cast<AForm &>(*this) = rrf;
	this->_target = rrf._target;
	std::cout << MAGHB "[ RobotomyRequestForm copy constructor assigment ]" reset << std::endl;
	std::cout << BLUHB << *this << reset << std::endl;
	return *this;
}

void RobotomyRequestForm::_execute(void) const {
	std::cout << "drilling noises -:)" << std::endl;
	std::srand(std::time(0));
	if (std::rand() % 2)
		std::cout << this->_target << " has been robotomized sucessfully." << std::endl;
	else
		throw RobotomyRequestForm::FailRobotomy();
}

const char *RobotomyRequestForm::FailRobotomy::what(void) const throw() {
	return (REDHB "Robotomy failed." reset);
}