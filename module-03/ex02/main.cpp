/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:45:51 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/24 20:37:19 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	FragTrap	bob = FragTrap("Bob");
	FragTrap	mario(bob);
	FragTrap	july = FragTrap("July");
	std::cout << std::endl;

	bob.getStatus();
	bob.attack("Ronaldinho");
	bob.takeDamage(3);
	bob.beRepaired(10);
	bob.getStatus();
	std::cout << std::endl;
	bob.highFivesGuys();


	mario.getStatus();
	mario.attack("Gaspar");
	mario.takeDamage(100);
	mario.beRepaired(10);
	mario.getStatus();
	std::cout << std::endl;
	mario.highFivesGuys();


	july.getStatus();
	for (int i = 0; i < 52; i++)
	{
		july.attack("Rock");
		july.beRepaired(10);
		july.takeDamage(3);
	}
	july.getStatus();
	std::cout << std::endl;
	july.highFivesGuys();
}