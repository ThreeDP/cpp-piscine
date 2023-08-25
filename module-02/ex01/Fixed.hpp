/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:02:14 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/24 21:05:14 by dapaulin         ###   ########.fr       */
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
		Fixed & operator=(Fixed const & rhs);

		int			toInt(void) const;
		float		toFloat(void) const;
		int			getRawBits(void) const;
		void		setRawBits(int const raw);
};

std::ostream & operator<<(std::ostream & os, Fixed const & integer);

#endif