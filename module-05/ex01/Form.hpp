/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 23:50:08 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/05 12:41:50 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_HPP__
# define __FORM_HPP__
# include <iostream>
class Bureaucrat;

class Form {
	private:
		const static int	_min = 150;
		const static int	_max = 1;
		const std::string	_name;
		bool				_sign;
		const int			_grade_to_sign;
		const int			_grade_to_exec;
		void				_validRange(int r);
		void				_setGradeToExec(int e);
		void				_setGradeToSign(int s);
	
	public:
		Form(void);
		Form(const std::string name, int sign, int exec);
		~Form(void);
		Form(Form const &f);
		Form &operator=(const Form &f);

		class GradeTooHighException : public std::exception {
			public:
				const char *what(void) const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
				const char *what(void) const throw();
		};

		void				beSigned(const Bureaucrat &b);
		bool				getSign(void) const;
		std::string			getName(void) const;
		int					getGradeSign(void) const;
		int					getGradeExec(void) const;
};

#include "Bureaucrat.hpp"

std::ostream &operator<<(std::ostream &os, Form const &f);

#endif