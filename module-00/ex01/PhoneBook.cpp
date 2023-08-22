/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:18:35 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/22 14:28:54 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	this->size = 0;
}

PhoneBook::~PhoneBook(void) {
	return ;
}

void	PhoneBook::reorderContacts(void) {
	for (int i = 0; i < 7; i++) {
		this->contact[i] = this->contact[i + 1];
	}
}

void	PhoneBook::add(void) {
	if (this->size == 8) {
		this->reorderContacts();
		this->contact[7].add_contact();
		return ;	
	}
	this->contact[this->size].add_contact();
	this->size++;
}

void	PhoneBook::viewUser(int i) {
	this->contact[i].showUser();
}

void	PhoneBook::showField(unsigned int setwords, std::string value, std::string separator) {
	if (value.size() > setwords) {
		value = value.substr(0, setwords - 1) + ".";
	}
	std::cout << std::right << std::setw(setwords) << value << separator;
}

void	PhoneBook::search(void) {
	int	index;

	std::cout << CLEAN_WINDOW;
	std::cout << "My Awesome PhoneBook" << std::endl;
	for (int i = 0; i < this->size; i++) {
		std::cout << std::right << std::setw(9) << i << " | ";
		this->showField(8, this->contact[i].getFName(), " | ");
		this->showField(8, this->contact[i].getLName(), " | ");
		this->showField(9, this->contact[i].getNickname(), "");
		std::cout << std::endl;
	}
	std::cout << std::endl << "Enter the index of the contact: ";
	if ((std::cin >> index) == 0) {
		std::cout << "Invalid input." << std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cin.get();
		return ;
	}
	std::cin.get();
	if (index >= 0 && index < this->size)
		this->viewUser(index);
	else {
		std::cout << CLEAN_WINDOW;
		std::cout << "The input is incorrect!" << std::endl;
	}
	std::cout << std::endl << "Press a keyword to continue..." << std::endl;
	std::cin.get();
}

void	PhoneBook::selectOption(bool incorrect_input) {
	std::cout << CLEAN_WINDOW;
	std::cout << "Enter the follows text for run a action:" << std::endl;
	std::cout << "ADD: save a new contact" << std::endl;
	std::cout << "SEARCH: display a specific contact" << std::endl;
	std::cout << "EXIT: finish the program" << std::endl;
	if (incorrect_input == true)
		std::cout << REDCOLOR"enter a correct option!"RESETCOLOR << std::endl;
	std::getline(std::cin, this->input);
}

void	PhoneBook::waitInput(void) {
	bool incorrect_input;

	incorrect_input = false;
	this->selectOption(incorrect_input);
	while (1)
	{
		if (std::cin.eof())
			break;
		if (this->input.compare("ADD") == 0) {
			this->add();
			incorrect_input = false;
		} else if (this->input.compare("SEARCH") == 0) {
			this->search();
			incorrect_input = false;
		} else if (this->input.compare("EXIT") == 0) {
			break;
		} else {
			incorrect_input = true;
		}
		this->selectOption(incorrect_input);
	}
}
