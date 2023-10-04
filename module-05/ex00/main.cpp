/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:48:49 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/03 23:39:20 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
	const std::string	const_name = "Jesus";
	std::string			name = "Jess";

	std::cout << std::endl;
	std::cout << BLUHB "\t[ out-of-range inc/dec ]\t" reset << std::endl;
	Bureaucrat			b2(name, 1);
	Bureaucrat			b1(const_name, 150);
	try {
		b2.levelUp();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		b1.levelDown();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << BLUHB "\t[ out-of-range init ]\t" reset << std::endl;
	try {
		Bureaucrat			b3(const_name, 151);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat			b4(name, 0);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << BLUHB "\t[ print message ]\t" reset << std::endl;
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	b1.levelUp();
	b2.levelDown();
	b1.levelUp();
	b2.levelDown();
}