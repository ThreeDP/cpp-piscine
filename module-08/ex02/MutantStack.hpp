/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:45:47 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/16 19:33:37 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MUTANT_STACK_HPP__
# define __MUTANT_STACK_HPP__

# include <iostream>
# include <algorithm>
# include <stack>
# include <list>
# include <iterator>
# include "define.hpp"

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void) : std::stack<T>(){}
		virtual ~MutantStack(void) {};
		MutantStack(const MutantStack &m) : std::stack<T>(m){};
		MutantStack &operator=(const MutantStack &m){
			if (this != &m) {
				std::stack<T>::operator=(m);
			}
			return *this;
		}

		typedef typename  std::stack<T>::container_type::iterator iterator;
		
		iterator begin() {
			return std::stack<T>::c.begin();
		}
		
		iterator end() {
			return std::stack<T>::c.end();
		}
		
		typedef typename  std::stack<T>::container_type::reverse_iterator reverse_iterator;

		reverse_iterator rbegin() {
			return std::stack<T>::c.rbegin();
		}

		reverse_iterator rend() {
			return std::stack<T>::c.rend();
		}
};

#endif 