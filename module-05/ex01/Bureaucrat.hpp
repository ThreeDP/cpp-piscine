/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:39:31 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/05 12:39:27 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_HPP__
# define __BUREAUCRAT_HPP__

#include <iostream>
#include "define.hpp"
#include "Form.hpp"

class Bureaucrat {
	private:
		const static int	_min = 1;
		const static int	_max = 150;
		const std::string	_name;
		int					_grade;
		void				_setGrade(int g);

	public:
		Bureaucrat(void);
		Bureaucrat(std::string n, int g);
		~Bureaucrat(void);
		Bureaucrat(Bureaucrat const &b);
		Bureaucrat &operator=(Bureaucrat const &b);

		class GradeTooHighException : public std::exception {
			public:
				const char *what(void) const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what(void) const throw();
		};
		
		const std::string	getName(void) const;
		int					getGrade(void) const;
		void				levelUp(void);
		void				levelDown(void);
		void				signForm(Form &f);
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b);

#endif