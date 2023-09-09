/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:39:54 by dapaulin          #+#    #+#             */
/*   Updated: 2023/09/09 16:22:20 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main()
{
	int		amount = 20;
	AAnimal	*animals[amount];

	for (int i = 0; i < amount / 2; i++) {
		animals[i] = new Dog();
	}
	for (int i = amount / 2 ; i < amount; i++) {
		animals[i] = new Cat();
	}
	for (int i = 0; i < amount; i++) {
		delete animals[i];
	}
	return 0;
}
