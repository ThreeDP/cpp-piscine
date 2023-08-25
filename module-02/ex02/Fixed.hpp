/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:02:14 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/24 22:04:19 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
# define __FIXED_HPP__

#include <iostream>
#include <cmath>

class Fixed {
	int					_number;
	static const int	_bits = 8;
	static const int	_max_limit = 0x7fffff;
	static const int	_min_limit = 0x800000;

	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const int n);
		Fixed(const float n);
		Fixed(Fixed const & integer);

		Fixed 				&operator=(Fixed const & rhs);
		Fixed				operator+(Fixed const &rhs);
		Fixed				operator-(Fixed const &rhs);
		Fixed				operator/(Fixed const &rhs);
		Fixed				operator*(Fixed const &rhs);
		
		bool				operator>(Fixed const &rhs) const;
		bool				operator<(Fixed const &rhs) const;
		bool				operator>=(Fixed const &rhs) const;
		bool				operator<=(Fixed const &rhs) const;
		bool				operator==(Fixed const &rhs) const;
		bool				operator!=(Fixed const &rhs) const;
	
		Fixed				operator++(int);
		Fixed				operator--(int);
		Fixed				&operator++(void);
		Fixed				&operator--(void);

		static const Fixed	&min(Fixed const &a, Fixed const &b);
		static const Fixed	&max(Fixed const &a, Fixed const &b);
		static Fixed		&min(Fixed &a, Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);

		int					toInt(void) const;
		float				toFloat(void) const;
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
};

std::ostream & operator<<(std::ostream & os, Fixed const & integer);

#endif