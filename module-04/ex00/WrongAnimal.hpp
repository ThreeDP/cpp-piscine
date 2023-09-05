/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:25:48 by dapaulin          #+#    #+#             */
/*   Updated: 2023/09/05 19:43:12 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONG_ANIMAL__
# define __WRONG_ANIMAL__

#include <iostream>

class WrongAnimal {
	protected:
		std::string	_type;
	public:
		WrongAnimal(void);
		~WrongAnimal(void);
		WrongAnimal(WrongAnimal const &wrongAnimal);
		WrongAnimal &operator=(WrongAnimal const &rhs);
	
	std::string		getType(void) const;
	void			makeSound(void) const;
};

#endif