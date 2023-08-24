/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:45:51 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/24 19:57:29 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
	ScavTrap	bob = ScavTrap("Bob");
	ScavTrap	mario(bob);
	ScavTrap	july = ScavTrap("July");
	std::cout << std::endl;

	bob.getStatus();
	bob.attack("Ronaldinho");
	bob.takeDamage(3);
	bob.beRepaired(10);
	bob.getStatus();

	mario.getStatus();
	mario.attack("Gaspar");
	mario.takeDamage(100);
	mario.beRepaired(10);
	mario.getStatus();

	july.getStatus();
	for (int i = 0; i < 26; i++)
	{
		july.attack("Rock");
		july.beRepaired(10);
		july.takeDamage(3);
	}
	july.getStatus();
}