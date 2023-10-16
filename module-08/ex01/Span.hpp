/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:13:35 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/16 00:11:38 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SPAN_HPP__
# define __SPAN_HPP__

# include <algorithm>
# include <iostream>
# include <iterator>
# include <vector>
# include "define.hpp"
# include <cmath>
# include <cstdlib> 

class Span {
	unsigned int		_N;
	std::vector<int>	_arr;

	public:
		Span(void);
		Span(unsigned int n);
		~Span(void);
		Span(const Span &s);
		Span			&operator=(const Span &s);


		void				addNumber(int n);
		void				addNumber(std::vector<int >::iterator b, std::vector<int >::iterator e);
		unsigned int		shortestSpan(void) const;
		unsigned int		longestSpan(void) const;
		unsigned int		size(void) const;
		std::vector<int>	getArr(void) const;
		unsigned int		getPos(void) const;

		class noRangeCanBeFound : public std::exception {
			public:
				const char *what(void) const throw();
		};

		class outOfRange : public std::exception {
			public:
				const char *what(void) const throw();
		};

		class itIsFull : public std::exception {
			public:
				const char *what(void) const throw();
		};

		int	&operator[](unsigned int i);
		int	&operator[](unsigned int i) const;
};

std::ostream &operator<<(std::ostream &os, Span const &s);

#endif