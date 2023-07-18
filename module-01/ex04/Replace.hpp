/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:16:07 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/18 19:13:05 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __REPLACE_HPP__
# define __REPLACE_HPP__

# include <iostream>
# include <string>
# include <fstream>
# ifndef __BUFFER_SIZE__
# define __BUFFER_SIZE__ 100
# endif

class Replace {
	const std::string	fileName;
	std::string	findString;
	std::string	replaceString;
	std::string	inString;
	std::string outString;
	void		getTextInFile(void);
	void		alterTextInFile(void);
	void		setTextInFile(void);

	public:
		Replace(std::string f, std::string s1, std::string s2);
		~Replace(void);
		std::string	replace(void);
};

#endif