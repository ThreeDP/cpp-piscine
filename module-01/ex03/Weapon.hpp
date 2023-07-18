/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:08:10 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/18 16:53:24 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON_HPP__
# define __WEAPON_HPP__

#include <iostream>

class Weapon {
	std::string type;
	
	public:
		Weapon(void);
		Weapon(std::string type);
		~Weapon(void);
		const std::string 	getType(void);
		void				setType(std::string type);
};

#endif