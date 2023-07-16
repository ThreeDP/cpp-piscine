/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:15:23 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/16 18:56:55 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONTACT_HPP__
# define __CONTACT_HPP__

# include <iostream>
# include <string>
# include <climits>
# include <iomanip>
# include "defines.hpp"

class Contact {
	std::string 	first_name;
	std::string		last_name;
	std::string		nickname;
	std::string		phone_number;
	std::string		darkest_secret;
	void			input_field(std::string label, std::string &value);

	public:
		Contact(void);
		~Contact(void);
		void		add_contact(void);
		std::string	getFName(void);
		std::string	getLName(void);
		std::string getNickname(void);
		void		showUser(void);
};

#endif