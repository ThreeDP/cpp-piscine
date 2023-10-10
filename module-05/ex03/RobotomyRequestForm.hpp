/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm copy.hpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:40:30 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/05 18:29:47 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ROBOTOMY_REQUEST_FORM_HPP__
# define __ROBOTOMY_REQUEST_FORM_HPP__

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {
	private:
		void			_execute(void) const;
		std::string		_target;
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm &scf);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &scf);
	
		class FailRobotomy : public std::exception {
			public:
				const char *what(void) const throw();
		};
};

#endif