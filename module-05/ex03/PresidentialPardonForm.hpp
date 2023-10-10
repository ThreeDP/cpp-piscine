/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:40:30 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/05 18:29:47 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRESIDENTIAL_PARDON_FORM_HPP__
# define __PRESIDENTIAL_PARDON_FORM_HPP__

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		void		_execute(void) const;
		std::string	_target;
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm &scf);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &scf);
};

#endif