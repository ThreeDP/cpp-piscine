/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:54:03 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/24 22:04:34 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _number(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int n) : _number(0) {
	std::cout << "Integer constructor called" << std::endl;
	if (n < this->_min_limit * -1)
		std::cerr << "Pass a greater num that " << this->_min_limit << std::endl;
	else if (n > this->_max_limit)
		std::cerr << "Pass a minor num that " << this->_max_limit << std::endl;
	else
		this->_number = n << Fixed::_bits;
}

Fixed::Fixed(const float n) : _number(0){
	std::cout << "Float constructor called" << std::endl;
	this->_number = (int)roundf(n * (1 << Fixed::_bits));
}

Fixed::Fixed(Fixed const & integer) {
	std::cout << "Copy constructor called" << std::endl;
	*this = integer;
}


int	Fixed::toInt(void) const {
	return (this->_number / (1 << Fixed::_bits));
}

float Fixed::toFloat(void) const {
	return ((float)this->_number / (1 << Fixed::_bits));
}

int	Fixed::getRawBits(void) const {
	return (this->_number);
}

void	Fixed::setRawBits(int const raw) {
	this->_number = raw;
}

Fixed & Fixed::operator=(Fixed const & rhs) {
	std::cout << "Copy assigment operator called" << std::endl;
	if (this != &rhs)
		this->_number = rhs.getRawBits();
	return *this;
}

std::ostream & operator<<(std::ostream & os, Fixed const & n) {
	os << n.toFloat();
	return (os);
}

Fixed	Fixed::operator+(Fixed const &rhs)
{
	return (this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(Fixed const &rhs)
{
	return (this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(Fixed const &rhs)
{
	return (this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(Fixed const &rhs)
{
	return (this->toFloat() / rhs.toFloat());
}

bool	Fixed::operator>(Fixed const &rhs) const
{
	return (this->toFloat() > rhs.toFloat());
}
bool	Fixed::operator<(Fixed const &rhs) const
{
	return (this->toFloat() < rhs.toFloat());
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
	return (this->toFloat() >= rhs.toFloat());
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	return (this->toFloat() <= rhs.toFloat());
}

bool	Fixed::operator==(Fixed const &rhs) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const &rhs) const
{
	return (this->getRawBits() != rhs.getRawBits());
}

Fixed	Fixed::operator++(int)
{
	Fixed prefix(*this);

	this->_number++;
	return prefix;
}

Fixed	&Fixed::operator++(void)
{
	this->_number++;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed prefix(*this);

	this->_number--;
	return prefix;
}

Fixed	&Fixed::operator--(void)
{
	this->_number--;
	return *this;
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a.toFloat() < b.toFloat())
		return a;
	return b;
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a.toFloat() > b.toFloat())
		return a;
	return b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.toFloat() < b.toFloat())
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return a;
	return b;
}
