/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:13:26 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/18 16:56:37 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMAN_B_HPP__
# define __HUMAN_B_HPP__

#include "Weapon.hpp"

class HumanB {
	std::string	name;
	Weapon		*gun;

	public:
		HumanB(void);
		HumanB(std::string name);
		~HumanB(void);
		void	attack(void);
		void	setWeapon(Weapon &gun);
};

#endif