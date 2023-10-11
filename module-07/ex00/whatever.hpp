/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:07:02 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/11 20:38:17 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WHATEVER_HPP__
# define __WHATEVER_HPP__

	# include <iostream>
	# include "define.hpp"

	template <typename T>
	void	swap(T &a, T &b) {
		T	c;
		c = a;
		a = b;
		b = c;
	}

	template <typename T>
	T	&min(T &a, T &b) {
		if (b <= a) {
			return b;
		}
		return a;
	}

	template <typename T>
	T	&max(T &a, T &b) {
		if (b >= a) {
			return b;
		}
		return a;
	}

	template <typename T>
	void	print2(T a, T b) {
		std::cout << GRNHB "[a: " << a << " ]" reset " " YELHB "[ b: " << b << " ]" reset << std::endl;
	}

	template <typename T>
	void	print(T a) {
		std::cout << GRNHB "[res: " << a << " ]" reset << std::endl;
	}

#endif