/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:38:23 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/22 13:47:56 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << HRED "Error" reset << std::endl;
		return (0);
	}
	RPN rpn(av[1]);
	try {
		rpn.filter();
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}