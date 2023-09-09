/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:18:39 by dapaulin          #+#    #+#             */
/*   Updated: 2023/09/09 16:24:25 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AANIMAL_HPP__
# define __AANIMAL_HPP__

# include <iostream>

class AAnimal {
	protected:
		std::string _type;
	public:
		AAnimal(void);
		virtual ~AAnimal(void);
		AAnimal(AAnimal const &Aanimal);
		AAnimal				&operator=(AAnimal const &rhs);

		std::string			getType(void) const;
		virtual void		makeSound(void) =0;
};

#endif