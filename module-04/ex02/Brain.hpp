/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:03:43 by dapaulin          #+#    #+#             */
/*   Updated: 2023/09/13 18:48:55 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__

#include <iostream>
# define __IDEAS_SIZE__ 100

# include "define.hpp"

class Brain {
	protected:
		std::string _ideas[__IDEAS_SIZE__];
		int 		_size;
	public:
		Brain(void);
		~Brain(void);
		Brain(Brain const &brain);
		Brain		&operator=(Brain const &rhs);
		std::string	getIdea(int i) const;

		void		setIdea(std::string idea);
		void		setIdeas(std::string *ideas, int size);
		void		printIdeas(void) const;
		int			getSize(void) const;
};

#endif