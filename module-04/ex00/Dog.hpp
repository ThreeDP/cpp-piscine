/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:27:40 by dapaulin          #+#    #+#             */
/*   Updated: 2023/09/05 19:20:54 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_HPP__
# define __DOG_HPP__

# include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog(void);
		~Dog(void);
		Dog(Dog const &dog);
		Dog			&operator=(Dog const &rhs);
		void		makeSound(void) const;
};

#endif