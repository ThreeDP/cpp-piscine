/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 23:12:50 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/10 11:43:02 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCALAR_CONVERTER__
# define __SCALAR_CONVERTER__

# include <iostream>
# include <sstream>
# include <cctype>
# include <iomanip>
# include <string>

# define __IMPOSSIBLE__ "impossible"
# define __NAN__ "nan"
# define __NANF__ "nanf"
# define __NON_DISPLAYABLE__ "Non displayable"

class ScalarConverter {
	private:
		static float		f;
		static double		d;
		static int			i;
		static char			c;
		static bool			ef;
		static bool			ed;
		static bool			ei;
		static bool			ec;
		static std::string	_errorHandler;
		static void			runConvert(void);
		static void 		runConvertChar(void);
		static void 		runConvertInt(void);
		static void 		runConvertFloat(void);
		static void 		runConvertDouble(void);
		static void			convertChar(std::string n);
		static void			convertInt(std::string n);
		static void			convertFloat(std::string n);
		static void			convertDouble(std::string n);
		static int			defineType(std::string n);

	public:
		ScalarConverter(void);
		~ScalarConverter(void);
		ScalarConverter(const ScalarConverter &sc);
		ScalarConverter &operator=(ScalarConverter const &sc);

		static void convert(std::string n);
};

#endif