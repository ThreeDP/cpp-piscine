/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:48:49 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/05 13:08:18 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
	Bureaucrat			b1("Rust", 80);
	Bureaucrat			b2("Gopher", 1);
	Form				*f1 = new Form();

	std::cout << std::endl;
	std::cout << BLUHB "\t[ Sign a Form ]\t" reset << std::endl;
	try {
		b1.signForm(*f1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		b2.signForm(*f1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		b1.signForm(*f1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << BLUHB "\t[ Create a Form ]\t" reset << std::endl;
	try {
		Form			f2("another", 0, 80);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form			f2("another", 151, 80);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form			f2("another", 80, 0);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form			f2("another", 0, 151);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << BLUHB "\t[ Copy a Form ]\t" reset << std::endl;
	std::cout << *f1 << std::endl;
	Form f2(*f1);
	std::cout << f2 << std::endl;
	Form f3;
	f3 = *f1;
	std::cout << f3 << std::endl;
	delete f1;
}