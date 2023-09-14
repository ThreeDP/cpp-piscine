/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:39:54 by dapaulin          #+#    #+#             */
/*   Updated: 2023/09/13 21:30:21 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void	TestCopy(AAnimal *animal, int i) {
	std::cout << std::endl;
	AAnimal	*X;
	if (i == 2) {
		animal->showBrain();
		X = new Dog(animal);
		X->showBrain();
	} else {
		animal->showBrain();
		X = new Cat(animal);
		X->showBrain();
	}
	X->makeSound();
	std::cout << std::endl;
	delete animal;
	delete X;
}

int main()
{
	// std::cout << std::endl << BHBLU "========== [ Test Copy ] ==========" reset << std::endl << std::endl;
	// TestCopy(new AAnimal(), 0);
	// std::cout << std::endl << BHBLU "===================================" reset << std::endl << std::endl;
	std::cout << std::endl << BHBLU "========== [ Test Copy ] ==========" reset << std::endl << std::endl;
	Cat *a = new Cat();
	a->getBrain()->setIdeas((std::string [2]){"milk", "bread"}, 2);
	TestCopy(a, 1);
	std::cout << std::endl << BHBLU "===================================" reset << std::endl << std::endl;
	std::cout << std::endl << BHBLU "========== [ Test Copy ] ==========" reset << std::endl << std::endl;
	Dog *b = new Dog();
	b->getBrain()->setIdeas((std::string [2]){"you shall not pass", "apple"}, 2);
	TestCopy(b, 2);
	std::cout << std::endl << BHBLU "===================================" reset << std::endl << std::endl;
	
	int		amount = 2;
	AAnimal	*animals[amount];

	for (int i = 0; i < amount / 2; i++) {
		animals[i] = new Dog();
	}
	for (int i = amount / 2; i < amount; i++) {
		animals[i] = new Cat();
	}
	std::cout << std::endl << std::endl;
	for (int i = 0; i < amount; i++) {
		delete animals[i];
	}
	std::cout << std::endl << std::endl;
	return 0;
}
