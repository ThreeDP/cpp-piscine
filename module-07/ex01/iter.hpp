/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:49:52 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/13 20:20:57 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ITER_HPP__
# define __ITER_HPP__

#include <iostream>
#include "define.hpp"

template<typename T>
void	iter(T *addr, int length, void (*fun)(T&)) {
	for (int i = 0; i < length; i++) {
		fun(addr[i]);
	}
}

template<typename T>
void	iter(const T *addr, int length, void (*fun)(const T&)) {
	for (int i = 0; i < length; i++) {
		fun(addr[i]);
	}
}

template<typename T>
void	plus(T &a) {
	a = a * 2;	
}

template<typename T>
void	printArray(T *a, int size) {
	std::cout << HGRN "[ ";
	for (int i = 0; i < size; i++) {
		if (i == size - 1) {
			std::cout << a[i] << " ]" reset << std::endl; 
		} else {
			std::cout << a[i] << ", "; 
		}
	}
}

#endif