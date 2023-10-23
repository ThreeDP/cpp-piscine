/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 10:33:17 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/22 17:15:14 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RPN_HPP__
# define __RPN_HPP__

# include "define.hpp"
# include <sstream>
# include <iostream>
# include <iomanip>
# include <algorithm>
# include <stack>

class RPN {
	std::string		_input;
	std::stack<int> _pm;
	RPN(void){};
	void				addNumber(char p);
	void				runOperation(char p);
	void				isValid(char p);
	
	public:
		RPN(std::string i);
		~RPN(void);	
		RPN(const RPN &rpn);
		RPN &operator=(const RPN &rpn);

		void					filter(void);
		const std::stack<int > 	&getPM(void) const;
		const std::string		&getInput(void) const;

		class errorRPN : public std::exception {
			public:
				const char * what() const throw() {
					return HRED "Error" reset;
				}
		};
};

#endif