/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:18:39 by dapaulin          #+#    #+#             */
/*   Updated: 2023/09/05 19:55:26 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

# include <iostream>

class Animal {
	protected:
		std::string _type;
	public:
		Animal(void);
		virtual ~Animal(void);
		Animal(Animal const &animal);
		Animal				&operator=(Animal const &rhs);

		std::string			getType(void) const;
		virtual void		makeSound(void) const;
};

#endif