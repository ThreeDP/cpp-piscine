/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 23:24:56 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/10 12:12:31 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "define.hpp"

char ScalarConverter::c = 0;
int ScalarConverter::i = 0;
float ScalarConverter::f = 0.0f;
double ScalarConverter::d = 0.0;
bool ScalarConverter::ef = false;
bool ScalarConverter::ed = false;
bool ScalarConverter::ei = false;
bool ScalarConverter::ec = false;
std::string ScalarConverter::_errorHandler = "";

ScalarConverter::ScalarConverter(void) {
	std::cout << GRNHB "[ Scalar Converter Constructor ]" reset << std::endl;
}

ScalarConverter::~ScalarConverter(void) {
	std::cout << REDHB "[ Scalar Converter Destructor ]" reset << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &sc) {
	std::cout << YELHB "[ Scalar Converter Copy Constructor ]" reset << std::endl;
	(void)sc;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &sc) {
	std::cout << BLUHB "[ Scalar Converter Assigment Operator ]" reset << std::endl;
	(void)sc;
	return *this;
}

void	ScalarConverter::runConvertChar(void) {
	if (ScalarConverter::ec || ScalarConverter::c < 0 \
		|| ScalarConverter::c > 127 \
		|| ScalarConverter::_errorHandler == __NANF__ \
		|| ScalarConverter::_errorHandler == __NAN__ \
		|| ScalarConverter::_errorHandler == __IMPOSSIBLE__)
		std::cout << "char: " << __IMPOSSIBLE__ << std::endl;
	else if (!isprint(ScalarConverter::c))
		std::cout << "char: " << __NON_DISPLAYABLE__ << std::endl;
	else
		std::cout << "char: '" << ScalarConverter::c << "'" << std::endl;
}

void	ScalarConverter::runConvertInt(void) {
	if (ScalarConverter::ei || ScalarConverter::_errorHandler == __NAN__ \
		|| ScalarConverter::_errorHandler == __NANF__ \
		|| ScalarConverter::_errorHandler == __IMPOSSIBLE__)
		std::cout << "int: " << __IMPOSSIBLE__ << std::endl;
	else
		std::cout << "int: " << ScalarConverter::i << std::endl;
}

void	ScalarConverter::runConvertFloat(void) {
	if (ScalarConverter::ef || ScalarConverter::_errorHandler == __IMPOSSIBLE__)
		std::cout << "float: " << __IMPOSSIBLE__ << std::endl;
	else if (ScalarConverter::_errorHandler == __NAN__ \
		|| ScalarConverter::_errorHandler == __NANF__)
		std::cout << "float: " << __NANF__ << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << ScalarConverter::f << "f" << std::endl;
}

void	ScalarConverter::runConvertDouble(void) {
	if (ScalarConverter::ed || ScalarConverter::_errorHandler == __IMPOSSIBLE__)
		std::cout << "double: " << __IMPOSSIBLE__ << std::endl;
	else if (ScalarConverter::_errorHandler == __NAN__ \
		|| ScalarConverter::_errorHandler == __NANF__)
		std::cout << "double: " << __NAN__ << std::endl;
	else 
		std::cout << "double: " << std::fixed << std::setprecision(1) << ScalarConverter::d << std::endl;
}

void	ScalarConverter::runConvert(void) {
	runConvertChar();
	runConvertInt();
	runConvertFloat();
	runConvertDouble();
}

void	ScalarConverter::convertChar(std::string n) {
	std::istringstream c(n);

	c >> ScalarConverter::c;
	if (n.length() != 1) {
		ScalarConverter::ec = true;
	} else if (!isprint(ScalarConverter::c)) {
		ScalarConverter::_errorHandler = __NON_DISPLAYABLE__;
	}
	ScalarConverter::i = static_cast<int >(ScalarConverter::c);
	ScalarConverter::f = static_cast<float >(ScalarConverter::c);
	ScalarConverter::d = static_cast<double >(ScalarConverter::c);
	runConvert();
}

void	ScalarConverter::convertInt(std::string n) {
	std::istringstream	iss(n);

	iss >> ScalarConverter::i;
	if (!iss) {
		ScalarConverter::_errorHandler = __IMPOSSIBLE__;
	}
	(ScalarConverter::i > 127 || ScalarConverter::i < 0) ? ScalarConverter::ec = true : ScalarConverter::c = static_cast<char >(ScalarConverter::i);
	ScalarConverter::f = static_cast<float >(ScalarConverter::i);
	ScalarConverter::d = static_cast<double >(ScalarConverter::i);
	runConvert();
}

void	ScalarConverter::convertFloat(std::string n) {
	std::istringstream	iss(n);

	iss >> ScalarConverter::f;
	if (n.length() >= 4 && n.substr(4) == __NANF__) {
		ScalarConverter::_errorHandler = __NANF__;
	} else if (n.length() >= 5 && n.substr(5) == "-inff") {
		ScalarConverter::f = __FLT_MIN__;
	} else if (n.length() >= 5 && n.substr(5) == "+inff") {
		ScalarConverter::f = __FLT_MAX__;
	} else if (!iss) {
		ScalarConverter::_errorHandler = __IMPOSSIBLE__;
	}
	(ScalarConverter::f > 127 || ScalarConverter::f < 0) ? ScalarConverter::ec = true : ScalarConverter::c = static_cast<char >(ScalarConverter::f);
	(ScalarConverter::f > static_cast<float >(__INT_MAX__) || ScalarConverter::f < static_cast<float >(-(__INT_MAX__) - 1)) ? ScalarConverter::ei = true : ScalarConverter::i = static_cast<int >(ScalarConverter::f);
	ScalarConverter::d = static_cast<double >(ScalarConverter::f);
	runConvert();
}

void	ScalarConverter::convertDouble(std::string n) {
	std::istringstream	iss(n);

	iss >> ScalarConverter::d;
	if (n.length() >= 3 && n.substr(0, 3) == __NAN__) {
		ScalarConverter::_errorHandler = __NAN__;
	} else if (n.length() >= 4 && n.substr(0, 4) == "-inf") {
		ScalarConverter::d = __DBL_MIN__;
	} else if (n.length() >= 4 && n.substr(0, 4) == "+inf") {
		ScalarConverter::d = __DBL_MAX__;
	} else if (!iss) {
		ScalarConverter::_errorHandler = __IMPOSSIBLE__;
	}
	(ScalarConverter::d > 127 || ScalarConverter::d < 0) ? ScalarConverter::ec = true : ScalarConverter::c = static_cast<char >(ScalarConverter::d);
	(ScalarConverter::d > static_cast<double >(__INT_MAX__) || ScalarConverter::f < static_cast<double >(-(__INT_MAX__) - 1)) ? ScalarConverter::ei = true : ScalarConverter::i = static_cast<int >(ScalarConverter::d);
	(ScalarConverter::d > __FLT_MAX__ || ScalarConverter::d < __FLT_MIN__) ? ScalarConverter::ef = true : ScalarConverter::f = static_cast<float >(ScalarConverter::d);
	runConvert();
}

int	ScalarConverter::defineType(std::string n) {
	int i = 0;
	int	res = 0;

	if ((n.length() >= 3 && n.substr(0, 3) == __NAN__) \
		|| (n.length() >= 4 && (n.substr(0, 4) == "+inf" \
		|| n.substr(0, 4) == "-inf")))
		return 3;
	if ((n.length() >= 4 && n.substr(0, 4) == __NANF__) \
		|| (n.length() >= 5 && (n.substr(0, 5) == "+inff" \
		|| n.substr(0, 5) == "-inff")))
		return 2;
	if (n.length() == 1 && !std::isdigit(n[0])) {
		return res;
	}
	res = 1;
	if (n[i] == '-' || n[i] == '+')
		i++;
	while (std::isdigit(n[i])) 
		i++;
	if (n[i] == '.')
		res = 3;
	while (std::isdigit(n[++i]))
		;
	if (n[i] == 'f')
		res = 2;
	return res;
}

void	ScalarConverter::convert(std::string n) {
	size_t pos = n.find_first_not_of(' ');
	if (pos != std::string::npos)
		n.erase(0, pos);
	switch (ScalarConverter::defineType(n)) {
		case 0:
			ScalarConverter::convertChar(n);
			break;
		case 1:
			ScalarConverter::convertInt(n);
			break;
		case 2:
			ScalarConverter::convertFloat(n);
			break;
		case 3:
			ScalarConverter::convertDouble(n);
			break;
		default:
			break;
	}
}