/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:16:54 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/11 20:47:14 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

void	intTest(void) {
	int a = 50;
	int b = 100;
	int res = 0;

	std::cout << REDHB "[           SWAP           ]" reset << std::endl;
	print2<int>(a, b);
	swap<int>(a, b);
	print2<int>(a, b);
	std::cout << std::endl;

	std::cout << REDHB "[           MIN           ]" reset << std::endl;
	print2<int>(a, b);
	res = min<int>(a, b);
	print<int>(res);
	std::cout << std::endl;

	std::cout << REDHB "[           MAX           ]" reset << std::endl;
	print2<int>(a, b);
	res = max<int>(a, b);
	print<int>(res);
	std::cout << std::endl;
}

void	floatTest(void) {
	float a = 99.9;
	float b = 66.6;
	float res = 0;

	std::cout << std::endl << REDHB "[           SWAP           ]" reset << std::endl;
	print2<float>(a, b);
	swap<float>(a, b);
	print2<float>(a, b);
	std::cout << std::endl;

	std::cout << REDHB "[           MIN           ]" reset << std::endl;
	print2<float>(a, b);
	res = min<float>(a, b);
	print<float>(res);
	std::cout << std::endl;

	std::cout << REDHB "[           MAX           ]" reset << std::endl;
	print2<float>(a, b);
	res = max<float>(a, b);
	print<float>(res);
	std::cout << std::endl;
}

void	stringTest(void) {
	std::string a = "whatsapp";
	std::string b = "facebook";
	std::string res = "";

	std::cout << std::endl << REDHB "[           SWAP           ]" reset << std::endl;
	print2<std::string>(a, b);
	::swap<std::string>(a, b);
	print2<std::string>(a, b);
	std::cout << std::endl;

	std::cout << REDHB "[           MIN           ]" reset << std::endl;
	print2<std::string>(a, b);
	res = min<std::string>(a, b);
	print<std::string>(res);
	std::cout << std::endl;

	std::cout << REDHB "[           MAX           ]" reset << std::endl;
	print2<std::string>(a, b);
	res = max<std::string>(a, b);
	print<std::string>(res);
	std::cout << std::endl;
}

void mainTest( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

int main(void) {

	intTest();
	floatTest();
	stringTest();
	mainTest();
	return 0;
}