/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:59:18 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/09 21:45:53 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN_HPP__
# define __INTERN_HPP__
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {
	public:
		Intern(void);
		~Intern(void);
		Intern(const Intern &i);
		Intern &operator=(Intern const &i);

		AForm *makeForm(std::string form, std::string target);
		class DoNotExitThisForm : public std::exception {
			public:
				const char *what(void) const throw();
		};
};

#endif