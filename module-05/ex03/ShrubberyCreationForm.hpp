/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:40:30 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/09 20:39:30 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHRUBBERY_CREATION_FORM_HPP__
# define __SHRUBBERY_CREATION_FORM_HPP__

# define __TREE__ "    ^    \n   ^^^   \n  ^^^^^  \n ^^^^^^^ \n^^^^^^^^^\n    |    \n"


#include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm {
	private:
		void		_execute(void) const;
		std::string	_target;
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm &scf);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &scf);

		class FileError : public std::exception {
			public:
				const char *what(void) const throw();
		};
};

#endif