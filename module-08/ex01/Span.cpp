/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:58:23 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/16 18:27:17 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _N(1), _arr(0) {
	this->_arr.reserve(this->_N);
}

Span::Span(unsigned int n) : _N(n), _arr(0) {
	this->_arr.reserve(this->_N);
}

Span::~Span(void) {
	
}

Span::Span(const Span &s) : _N(s.size()), _arr(0) {
	if (this != &s) {
		*this = s;
	}
}

Span	&Span::operator=(const Span &s) {
	if (this != &s) {
		this->_N = s.size();
		this->_arr.reserve(this->_N);
		this->_arr = s.getArr();
	}
	return (*this);
}

unsigned int	Span::size(void) const {
	return this->_N;
}

std::vector<int> 	Span::getArr(void) const {
	return this->_arr;
}

unsigned int 	Span::getPos(void) const {
	return this->_arr.size();
}

int		&Span::operator[](unsigned int i) {
	if (i >= this->_N) {
		throw outOfRange();
		return this->_arr[0];
	}
	return this->_arr[i];
}

int		&Span::operator[](unsigned int i) const {
	if (i >= this->_N) {
		throw outOfRange();
		return const_cast<int &>(this->_arr[0]);
	}
	return const_cast<int &>(this->_arr[i]);
}

void	Span::addNumber(int n) {
	if (this->_arr.size() < this->_N) {
		this->_arr.push_back(n);
		return ;
	}
	throw itIsFull();
}

void	Span::addNumber(std::vector<int >::iterator b, std::vector<int >::iterator e) {
	if (this->_arr.size() + std::distance(b, e) <= this->_N) {
		this->_arr.insert(this->_arr.end(), b, e);
		return ;
	}
	throw itIsFull();
}

unsigned int	Span::shortestSpan(void) const {
	unsigned int res = 0;
	if (this->_arr.empty() || this->_arr.size() == 1) {
		throw noRangeCanBeFound();
	}
	std::vector<int >arr = this->_arr;
	res = std::abs(this->_arr[0] - this->_arr[1]);
	for (std::vector<int >::iterator it = arr.begin() + 2; it != arr.end(); ++it) {
		if ((int)res > std::abs(*(it - 1) - *it)) {
			res = std::abs(*(it - 1) - *it);
		}
	}
	return res;
}

unsigned int	Span::longestSpan(void) const {
	unsigned int res = 0;
	if (this->_arr.empty() || this->_arr.size() == 1) {
		throw noRangeCanBeFound();
	}
	std::vector<int >arr = this->_arr;
	res = std::abs(this->_arr[0] - this->_arr[1]);
	for (std::vector<int >::iterator it = arr.begin() + 2; it != arr.end(); ++it) {
		if ((int)res < std::abs(*(it - 1) - *it)) {
			res = std::abs(*(it - 1) - *it);
		}
	}
	return res;
}

const char	*Span::noRangeCanBeFound::what(void) const throw() {
	return ( HRED "No range can be found." reset);
}

const char	*Span::outOfRange::what(void) const throw() {
	return ( HRED "Out of range." reset);
}

const char	*Span::itIsFull::what(void) const throw() {
	return ( HRED "It's full." reset);
}

std::ostream &operator<<(std::ostream &os, Span const &s) {
	unsigned int size = s.getPos();
	os << HYEL << "[ ";
	for (unsigned int i = 0; i < size; i++) {
		if (i == size - 1) {
			os << s[i] << " ]" reset << "\t";
			continue;
		}
		os << s[i] << ", ";
	}
	os << HBLU "[ Longest: " << s.longestSpan() << " ]" reset "\t " HGRN "[ Shortest: " << s.shortestSpan() << "] " reset "\t";
	os << HCYN "[ size: " << s.size() << " ]" reset " " HMAG "[ filled: " << size << " ]" reset << std::endl;
	return (os);
}