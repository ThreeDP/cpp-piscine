/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:26:54 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/13 19:08:39 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EASY_FIND_HPP__
# define __EASY_FIND_HPP__

# include <iostream>

template <typename T>
int	easyfind(T &c, int v) {
	int size = c.size();
	for (int i = 0; i < size; i++) {
		if (c[i] == v) {
			return c[i];		
		}
	}
	throw std::out_of_range("Value not found!");
	return -1;
}

#endif