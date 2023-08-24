/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:45:51 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/24 18:09:23 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap	bob = ClapTrap("Bob");
	ClapTrap	mario(bob);
	ClapTrap	july = ClapTrap("July");
	std::cout << std::endl;

	bob.getStatus();
	bob.attack("Ronaldinho");
	bob.takeDamage(3);
	bob.beRepaired(10);
	bob.getStatus();

	mario.getStatus();
	mario.attack("Gaspar");
	mario.takeDamage(10);
	mario.beRepaired(10);
	mario.getStatus();

	july.getStatus();
	july.attack("Rock");
	july.takeDamage(3);
	july.attack("Rock");
	july.takeDamage(3);
	july.attack("Rock");
	july.takeDamage(3);
	july.beRepaired(10);
	july.getStatus();
	july.attack("Rock");
	july.takeDamage(3);
	july.attack("Rock");
	july.takeDamage(3);
	july.attack("Rock");
	july.takeDamage(3);
	july.beRepaired(10);
	july.getStatus();
	july.attack("Rock");
	july.takeDamage(3);
	july.attack("Rock");
	july.takeDamage(3);
	july.attack("Rock");
	july.takeDamage(3);
	july.beRepaired(10);
	july.getStatus();
}