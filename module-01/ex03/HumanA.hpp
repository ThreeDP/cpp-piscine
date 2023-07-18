/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:16:45 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/18 16:55:14 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMAN_A_HPP__
# define __HUMAN_A_HPP__

#include "Weapon.hpp"

class HumanA {
	std::string	name;
	Weapon		&gun;

	public:
		HumanA(std::string name, Weapon &gun);
		~HumanA(void);
		void	attack(void);
};

#endif