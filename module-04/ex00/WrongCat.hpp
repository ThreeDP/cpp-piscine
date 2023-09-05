/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:38:35 by dapaulin          #+#    #+#             */
/*   Updated: 2023/09/05 19:38:39 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONG_CAT_HPP__
# define __WRONG_CAT_HPP__

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat(void);
		~WrongCat(void);
		WrongCat(WrongCat const &wrongcat);
		WrongCat	&operator=(WrongCat const &rhs);
		void		makeSound(void) const;	
};

#endif