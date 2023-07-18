/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:24:11 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/18 16:03:13 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main() {
	std::string s = "HI THIS IS BRAIN";
	std::string	*ptr = &s;
	std::string	&ref = s;
	
	std::cout << "The memory address of the string variable: " << &s << std::endl;
	std::cout << "The memory address held by ptr: " << &ptr << std::endl;
	std::cout << "The memory address held by ref: " << &ref << std::endl;
	std::cout << std::endl;
	std::cout << "The value of the string variable: " << s << std::endl;
	std::cout << "The value pointed to by ptr: " << *ptr << std::endl;
	std::cout << "The value pointed to by ref: " << ref << std::endl;
}