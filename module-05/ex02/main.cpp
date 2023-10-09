/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:48:49 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/09 07:31:10 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	SCF_test(void) {
	Bureaucrat			b1("Rust", 80);
	Bureaucrat			b2("Gopher", 150);
	AForm				*f1 = new 	ShrubberyCreationForm("life");

	b1.signAForm(*f1);
	try {
		b1.executeForm(*f1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	ShrubberyCreationForm				f2("test");
	b2.signAForm(f2);
	try {
		b2.executeForm(f2);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	ShrubberyCreationForm				f3(f2);
	ShrubberyCreationForm				f4;

	f4 = f2;
	
	std::cout << std::endl << REDHB "[      Clean      ]" reset << std::endl << std::endl;
	delete f1;
}

void	Rob(void) {
	Bureaucrat			b1("Rust", 20);
	Bureaucrat			b2("Gopher", 150);
	AForm				*f1 = new 	RobotomyRequestForm("life");

	b1.signAForm(*f1);
	try {
		b1.executeForm(*f1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	RobotomyRequestForm				f2("test");
	b2.signAForm(f2);
	try {
		b2.executeForm(f2);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	RobotomyRequestForm				f3(f2);
	RobotomyRequestForm				f4;

	f4 = f2;
	
	std::cout << std::endl << REDHB "[      Clean      ]" reset << std::endl << std::endl;
	delete f1;
}

void	Presidential(void) {
	Bureaucrat			b1("Rust", 80);
	Bureaucrat			b2("Gopher", 150);
	AForm				*f1 = new 	PresidentialPardonForm("life");

	b1.signAForm(*f1);
	try {
		b1.executeForm(*f1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	PresidentialPardonForm				f2("test");
	b2.signAForm(f2);
	try {
		b2.executeForm(f2);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	PresidentialPardonForm				f3(f2);
	PresidentialPardonForm				f4;

	f4 = f2;
	
	std::cout << std::endl << REDHB "[      Clean      ]" reset << std::endl << std::endl;
	delete f1;
}

int main(void) {
	SCF_test();
	Rob();
	Presidential();
}