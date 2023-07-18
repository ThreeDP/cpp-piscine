/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:06:36 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/18 14:19:49 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_HPP__
# define __ZOMBIE_HPP__

# include <iostream>

class Zombie {
	std::string name;
	
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		void	setName(std::string name);
		void	announce(void);
};

Zombie	*zombieHorde(int n, std::string name);

#endif