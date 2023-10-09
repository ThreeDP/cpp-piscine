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

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("comic book", 72, 45) {
	std::cout << GRNHB "[ RobotomyRequestForm base constructor ]" reset << std::endl;
	std::cout << *this << std::endl;
	std::cout << BLUHB << *this << reset << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45) {
	std::cout << GRNHB "[ RobotomyRequestForm constructor ]" reset << std::endl;
	std::cout << *this << std::endl;
	std::cout << BLUHB << *this << reset << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << REDHB "[ RobotomyRequestForm destructor ]" reset << std::endl;
	std::cout << *this << std::endl;
	std::cout << BLUHB << *this << reset << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &scf) : AForm(scf) {
	std::cout << YELHB "[ RobotomyRequestForm copy constructor ]" reset << std::endl;
	std::cout << *this << std::endl;
	std::cout << BLUHB << *this << reset << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &scf) {
	std::cout << *this << std::endl;
	reinterpret_cast<AForm &>(*this) = scf;
	std::cout << MAGHB "[ RobotomyRequestForm copy constructor assigment ]" reset << std::endl;
	std::cout << BLUHB << *this << reset << std::endl;
	return *this;
}

void RobotomyRequestForm::_execute(const Bureaucrat &b) const {
	std::cout << "drilling noises -:)" << std::endl;
	std::srand(std::time(0));
	if (std::rand() % 2)
		std::cout << b << " has been robotomized sucessfully." << std::endl;
	else
		throw RobotomyRequestForm::FailRobotomy();
}

const char *RobotomyRequestForm::FailRobotomy::what(void) const throw() {
	return (REDHB "Robotomy failed." reset);
}