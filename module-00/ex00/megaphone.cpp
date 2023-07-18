/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:18:45 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/18 12:48:15 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

std::string ftToUpper(const std::string s) {
	std::string str;
	int			size;

	size = s.size();
	for (int i = 0; i < size; i++) {
		str += std::toupper(s.at(i));
	}
	return str;
}

int main(int ac, char **av) {
	if (ac > 1) {
		for (int i = 1; i < ac; i++) {
			(i != ac - 1) ? std::cout << ftToUpper(av[i]) << " " :
							std::cout << ftToUpper(av[i]);
		}
		std::cout << std::endl;
		return 0;
	}
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}