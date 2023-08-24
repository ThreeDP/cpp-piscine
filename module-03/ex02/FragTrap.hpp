/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:18:38 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/24 20:23:51 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAG_TRAP_HPP__
# define __FRAG_TRAP_HPP__

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap(void);
		FragTrap(const std::string name);
		~FragTrap(void);
		FragTrap(FragTrap const & ft);
		FragTrap &operator=(FragTrap const &rhs);
		
		void		attack(const std::string &target);
		void		highFivesGuys(void);		
};

#endif