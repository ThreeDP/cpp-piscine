/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:39:52 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/22 10:23:51 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout <<HRED "Error: " HYEL "could not open file." reset;
		return (1);
	}
	BitcoinExchange b(av[1]);
	b.startProcess();
    return 0;
}