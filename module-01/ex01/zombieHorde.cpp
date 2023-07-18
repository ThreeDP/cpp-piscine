/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:07:01 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/18 14:20:11 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int n, std::string name) {
	Zombie	*z;

	z = new Zombie[n];
	for (int i = 0; i < n; i++) {
		z->setName(name);
	}
	return (z);
}