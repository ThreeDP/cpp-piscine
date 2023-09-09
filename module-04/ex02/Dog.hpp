/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:27:40 by dapaulin          #+#    #+#             */
/*   Updated: 2023/09/09 16:28:22 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_HPP__
# define __DOG_HPP__

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal {
	private:
		Brain	*brain;
	public:
		Dog(void);
		~Dog(void);
		Dog(Dog const &dog);
		Dog			&operator=(Dog const &rhs);
		Brain*		getBrain(void) const;
		void		makeSound(void);
};

#endif