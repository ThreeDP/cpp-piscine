/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:48:49 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/09 21:49:38 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void) {
	Intern someRandomIntern;
	AForm* rrf;
	AForm* scf;
	AForm* ppf;
	AForm* nothing;
	try {
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		scf = someRandomIntern.makeForm("shrubbery creation", "jb");
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		ppf = someRandomIntern.makeForm("presidential pardon", "julios");
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		nothing = someRandomIntern.makeForm("nothing", "");
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	delete rrf;
	delete scf;
	delete ppf;
}