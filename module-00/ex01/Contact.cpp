/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:16:55 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/16 16:04:43 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact(void) {
	this->first_name = "";
	this->last_name = "";
	this->nickname = "";
	this->phone_number = "";
	this->darkest_secret = "";
}

Contact::~Contact(void) {
	return ;
}

void	Contact::input_field(std::string label, std::string &value) {
	int	i;

	i = 0;
	do {
		std::cout << CLEAN_WINDOW;
		std::cout << label;
		if (i > 0) {
			std::cout << std::endl << REDCOLOR"enter a nonempty value!"RESETCOLOR;
			std::cout << "\033[" << 1 << ";" << label.size() + 1 << "H";	
		}
		std::getline(std::cin, value);
		i++;
	}
	while (value == "");
}

void Contact::add_contact(void) {
	this->input_field("Enter first name: ", this->first_name);
	this->input_field("Enter last name: ", this->last_name);
	this->input_field("Enter nickname: ", this->nickname);
	this->input_field("Enter the phone number: ", this->phone_number);
	this->input_field("Enter the darkest secret: ", this->darkest_secret);
}

std::string	Contact::getFName(void) {
	return this->first_name;
}

std::string Contact::getLName(void) {
	return this->last_name;
}

std::string Contact::getNickname(void) {
	return this->nickname;
}

void Contact::showUser(void) {
	std::cout << CLEAN_WINDOW;
	std::cout << "first name: " << this->first_name << std::endl;
	std::cout << "last name: " << this->last_name << std::endl;
	std::cout << "nickname: " << this->nickname << std::endl;
	std::cout << "phone number: " << this->phone_number << std::endl;
	std::cout << "darkest secret: " << this->darkest_secret << std::endl;
}