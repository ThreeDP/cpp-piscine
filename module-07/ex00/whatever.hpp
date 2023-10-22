/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:07:02 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/13 20:15:05 by dapaulin         ###   ########.fr       */
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
	const T	&min(const T &a, const T &b) {
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
	const T	&max(const T &a, const T &b) {
		if (b >= a) {
			return b;
		}
		return a;
	}

	template <typename T>
	void	print2(const T a, const T b) {
		std::cout << HGRN "[a: " << a << " ]" reset " " HYEL "[ b: " << b << " ]" reset << std::endl;
	}

	template <typename T>
	void	print(const T a) {
		std::cout << HGRN "[res: " << a << " ]" reset << std::endl;
	}

#endif