/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:39:54 by dapaulin          #+#    #+#             */
/*   Updated: 2023/09/05 20:20:04 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "[ Virtual Set ]" << std::endl << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	j->makeSound();
	i->makeSound(); //will output the cat sound!
	meta->makeSound();

	std::cout << std::endl;
	delete meta;
	delete j;
	delete i;

	std::cout << std::endl;
	std::cout << "[ Virtual Don't Set ]" << std::endl << std::endl;
	const WrongAnimal* go = new WrongAnimal();
	WrongCat *cat = new WrongCat();
	const WrongAnimal* rust = cat;
	
	std::cout << std::endl;
	std::cout << go->getType() << " " << std::endl;
	std::cout << rust->getType() << " " << std::endl;
	go->makeSound();
	rust->makeSound();
	
	std::cout << std::endl;
	delete go;
	delete cat;
	return 0;
}