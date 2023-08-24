/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:35:22 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/24 18:52:47 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAP_TRAP_HPP__
# define __CLAP_TRAP_HPP__

#include <iostream>

class ClapTrap {
	
	protected:
		std::string		_name;
		int				_hit;
		int				_energy;
		int				_damage;
	
	public:
		ClapTrap(void);
		ClapTrap(const std::string name);
		~ClapTrap(void);
		ClapTrap(ClapTrap const & ct);
		ClapTrap & operator=(ClapTrap const & rhs);

		void			attack(const std::string &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

		std::string		getName(void) const;
		unsigned int	getHit(void) const;
		unsigned int	getEnergy(void) const;
		unsigned int	getDamage(void) const;
		void			getStatus(void) const;
};

#endif