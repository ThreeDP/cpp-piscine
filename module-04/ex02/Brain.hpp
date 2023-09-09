/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:03:43 by dapaulin          #+#    #+#             */
/*   Updated: 2023/09/08 18:27:05 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__

#include <iostream>
# define __IDEAS_SIZE__ 100

class Brain {
	protected:
		std::string _ideas[__IDEAS_SIZE__];
	public:
		Brain(void);
		~Brain(void);
		Brain(Brain const &brain);
		Brain		&operator=(Brain const &rhs);
		std::string	getIdea(int i) const;
};

#endif