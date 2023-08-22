/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:18:39 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/22 14:41:50 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONE_BOOK_HPP__
# define __PHONE_BOOK_HPP__

# include "Contact.hpp"

class PhoneBook {
	int			size;
	std::string	input;
	Contact		contact[8];
	void		add(void);
	void		search(void);
	void		viewUser(int i);
	void		selectOption(bool incorrect_input);
	void		showField(unsigned int setwords, std::string value, std::string separator);
	void		reorderContacts(void);
	
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	waitInput(void);
};

#endif