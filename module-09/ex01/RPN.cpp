/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 11:08:08 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/22 13:46:55 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string i) : _input(i) {
	std::cout << HGRN "[ RPN Constructor ]" reset << std::endl;
}

RPN::~RPN(void) {
	std::cout << HRED "[ RPN Destructor ]" reset << std::endl;
}

RPN::RPN(const RPN &rpn) {
	*this = rpn;
}

RPN	&RPN::operator=(const RPN &rpn) {
	if (this != &rpn) {
		this->_input = rpn.getInput();
		this->_pm = rpn.getPM();
	}
	return *this;
}

void	RPN::addNumber(char p) {
	if (std::isdigit(p)) {
		this->_pm.push((int)p - '0');
	} 
}

void	RPN::runOperation(char p) {
	int size = this->_pm.size();
	if ((p == '*' || p == '/' || p == '-' || p == '+')) {
		if (p == '*' && size >= 2) {
			int num = this->_pm.top();
			this->_pm.pop();
			this->_pm.top() *= num;
		} else if (p == '/' && size >= 2) {
			int num = this->_pm.top();
			this->_pm.pop();
			this->_pm.top() /=	num;
		} else if (p == '+' && size >= 2) {
			int num = this->_pm.top();
			this->_pm.pop();
			this->_pm.top() += num;
		} else if (p == '-' && size >= 2) {
			int num = this->_pm.top();
			this->_pm.pop();
			this->_pm.top() -= num;
		} else {
			throw errorRPN();
		}
	}
}

void	RPN::filter(void) {
	for (int i = 0; this->_input[i]; i++) {
		char	p = this->_input.at(i);
		this->addNumber(p);
		this->runOperation(p);
		if (!this->_input[i]) {
			break ;
		}
		while (this->_input[i + 1] && std::isspace(this->_input[i + 1]))  {
			i++;
		}
	}
	if (this->_pm.size() != 1) {
		throw errorRPN();
	} else {
		std::cout << HYEL << this->_pm.top() << reset << std::endl;
	}
}

const std::stack<int > 	&RPN::getPM(void) const {
	return this->_pm;
}

const std::string		&RPN::getInput(void) const {
	return this->_input;
}
