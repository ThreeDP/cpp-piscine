/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:26:54 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/16 01:26:09 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EASY_FIND_HPP__
# define __EASY_FIND_HPP__

# include "define.hpp"
# include <iostream>
# include <algorithm>
# include <list>
# include <vector>
# include <iterator>

template <typename T>
typename T::iterator	easyfind(T &c, int v) {
	typename T::iterator it = std::find(c.begin(), c.end(), v);
	if (it == c.end()) {
		throw std::out_of_range("Value not found!");
	}
	return it;
}

#endif