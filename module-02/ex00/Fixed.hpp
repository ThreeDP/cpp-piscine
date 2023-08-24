/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:02:14 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/23 22:58:35 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
# define __FIXED_HPP__

#include <iostream>

class Fixed {
	int					_number;
	static const int	_bits = 8;

	public:
		Fixed(void);
		~Fixed(void);
		Fixed(Fixed const & integer);
		Fixed & operator=(Fixed const & rhs);

		int			getRawBits(void) const;
		void		setRawBits(int const raw);
};

#endif