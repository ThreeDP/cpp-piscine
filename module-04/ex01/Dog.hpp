/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:27:40 by dapaulin          #+#    #+#             */
/*   Updated: 2023/09/13 18:59:11 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_HPP__
# define __DOG_HPP__

# include "define.hpp"
# include "Brain.hpp"
# include "Animal.hpp"

class Dog : public Animal {
	private:
		Brain	*brain;
	public:
		Dog(void);
		~Dog(void);
		Dog(Dog const &dog);
		Dog(Animal const *dog);
		Dog			&operator=(Dog const &rhs);
		Brain*		getBrain(void) const;
		void		makeSound(void) const;
		void		showBrain(void) const;
};

#endif