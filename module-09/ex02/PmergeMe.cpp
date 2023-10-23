/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:25:29 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/22 23:30:48 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

// template <typename T, template <typename, typename> class C>
// PmergeMe<T, C >	&PmergeMe<T, C >::operator=(const PmergeMe<T, C > &pm) {
// 	if (this != &pm) {
// 		this->_arr = pm.getArr();
// 	}
// 	return *this;
// }

// template <typename T, template <typename, typename> class C>
// const C<T , std::allocator<T> > &PmergeMe<T, C>::getArr(void) const {
//     return this->_arr;
// }


// template <typename T, template <typename, typename> class C>
// void	PmergeMe<T, C >::sort(void) {
// 	if (this->_arr.size() == 1) {
// 		return ;
// 	}
// 	this->makePairs();
// }

// template <typename T, template <typename, typename> class C>
// void	PmergeMe<T, C >::makePairs(void) {
// 	if (this->_arr.size() % 2 != 0) {
// 		this->_remainder = this->_arr.back();
// 		this->_arr.pop_back();
// 	}
// 	while (!this->_arr.empty()) {
// 		C<T, std::allocator<T> > pt;
// 		pt.push_back(this->_arr.front());
// 		this->_arr.pop_front();
// 		pt.push_back(this->_arr.front());
// 		this->_arr.pop_front();
// 		pt.sort();
// 		std::sort(pt.rbegin(), pt.rend());
// 		this->_pairs.push_back(pt);
// 	}
// 	for (typename std::vector<C<T, std::allocator<T> > >::iterator it = this->_pairs.begin(); it != this->_pairs.end(); ++it) {
// 		std::cout << *it << std::endl;
// 	}
// }

// template <typename T, template <typename, typename> class C>
// C<T, std::allocator<T> >	PmergeMe<T, C >::createInput(char **av) {
// 	C<T, std::allocator<T> >		array;

// 	for (int i = 0; av[i]; i++) {
// 		int	num = 0;
// 		std::istringstream is(av[i]);
// 		is >> num;
// 		if (!is) {
// 			throw errorPmergeMe();
// 		}
// 		if (num > 2147483647 || num < -2147483648) {
// 			throw errorPmergeMe();
// 		}
// 		array.push_back(num);
// 	}
// 	return array;
// }