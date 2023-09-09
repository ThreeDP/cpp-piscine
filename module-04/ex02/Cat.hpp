/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:10:02 by dapaulin          #+#    #+#             */
/*   Updated: 2023/09/09 16:28:51 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_HPP__
# define __CAT_HPP__

# include "Brain.hpp"
# include "AAnimal.hpp"

class Cat : public AAnimal {
	private:
		Brain *brain;
	public:
		Cat(void);
		~Cat(void);
		Cat(Cat const &cat);
		Cat			&operator=(Cat const &rhs);
		Brain*		getBrain(void) const;
		void		makeSound(void);	
};

#endif