/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:51:43 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/24 19:07:01 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCAV_TRAP_HPP__
# define __SCAV_TRAP_HPP__

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(void);
		ScavTrap(const std::string name);
		~ScavTrap(void);
		ScavTrap(ScavTrap const & st);
		ScavTrap &operator=(ScavTrap const &rhs);

		void		attack(const std::string & target);
		void		guardGate(void);
};

#endif