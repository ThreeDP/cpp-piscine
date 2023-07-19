/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:42:04 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/19 18:24:20 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {
	this->keymap[0] = std::make_pair("DEBUG", &Harl::debug);
	this->keymap[1] = std::make_pair("INFO", &Harl::info);
	this->keymap[2] = std::make_pair("WARNING", &Harl::warning);
	this->keymap[3] = std::make_pair("ERROR", &Harl::error);
}

Harl::~Harl(void) {
	return ;
}

void	Harl::printMessage(std::string label, std::string description) {
	std::cout << "[" << label << "]" << std::endl;
	std::cout << description << std::endl;
}

void	Harl::debug(void) {
	this->printMessage("DEBUG", "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!");
}

void	Harl::info(void) {
	this->printMessage("INFO", "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!");
}

void	Harl::warning(void) {
	this->printMessage("WARNING", "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.");
}

void	Harl::error(void) {
	this->printMessage("ERROR", "This is unacceptable! I want to speak to the manager now.");
}

void	Harl::complain(std::string level) {
	for (int i = 0; i < 4; i++) {
		if (this->keymap[i].first == level) {
			(this->*keymap[i].second)();
			return ;
		}
	}
	std::cout << "Invalid alternative" << std::endl;
}