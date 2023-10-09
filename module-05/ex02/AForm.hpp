/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 23:50:08 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/09 05:55:38 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_HPP__
# define __FORM_HPP__
# include <iostream>
class Bureaucrat;

class AForm {
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
	protected:
		virtual void		_execute(Bureaucrat const &executor) const =0;
	public:
		AForm(void);
		AForm(const std::string name, int sign, int exec);
		virtual ~AForm(void);
		AForm(AForm const &f);
		virtual AForm &operator=(const AForm &f);

		class GradeTooHighException : public std::exception {
			public:
				const char *what(void) const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
				const char *what(void) const throw();
		};

		class IsNotSigned : public std::exception {
			public:
				const char *what(void) const throw();
		};

		void				beSigned(const Bureaucrat &b);
		bool				getSign(void) const;
		std::string			getName(void) const;
		int					getGradeSign(void) const;
		int					getGradeExec(void) const;
		bool				isSigned(void) const;
		void				execute(Bureaucrat const &executor) const;
};

#include "Bureaucrat.hpp"

std::ostream &operator<<(std::ostream &os, AForm const &f);

#endif