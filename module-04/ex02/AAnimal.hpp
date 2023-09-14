/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:18:39 by dapaulin          #+#    #+#             */
/*   Updated: 2023/09/13 21:29:05 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AANIMAL_HPP__
# define __AANIMAL_HPP__

# include <iostream>
# include "define.hpp"

class AAnimal {
	protected:
		std::string _type;
	public:
		AAnimal(void);
		virtual ~AAnimal(void);
		AAnimal(AAnimal const &animal);
		virtual AAnimal& operator=(const AAnimal &rhs);

		std::string			getType(void) const;
		virtual void		makeSound(void) const =0;
		virtual void		showBrain(void) const =0;
};

#endif