/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:12:51 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/23 18:51:33 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	Zombie	*z;
	int		num = 10;

	z = zombieHorde(num, "Jesus");
	for (int i = 0; i < num; i++) {
		z[i].announce();
	}
	delete[] z;
}