/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:31:08 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/19 18:03:18 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL_HPP__
# define __HARL_HPP__

#include <iostream>

class Harl {
	std::pair<std::string, void (Harl::*)(void)> keymap[4];
	void			f(void);
	void			debug(void);
	void			info(void);
	void			warning(void);
	void			error(void);
	void			printMessage(std::string label, std::string description);

	public:
		Harl(void);
		~Harl(void);
		void	complain(std::string level);
};

#endif