/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:10:02 by dapaulin          #+#    #+#             */
/*   Updated: 2023/09/05 19:21:06 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_HPP__
# define __CAT_HPP__

# include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat(void);
		~Cat(void);
		Cat(Cat const &cat);
		Cat			&operator=(Cat const &rhs);
		void		makeSound(void) const;	
};

#endif