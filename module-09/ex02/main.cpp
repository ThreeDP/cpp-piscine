/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:28:31 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/22 23:26:16 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

void	print(std::vector<unsigned int> &a) {
	std::cout << HYEL "before: " reset;
	std::cout << HGRN "[ ";
	for (std::vector<unsigned int>::reverse_iterator it = a.rbegin(); it != a.rend(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << "]" reset << std::endl;	
}

int main(int ac, char **av) {
	if (ac == 1) {
		return (0);
	}
	av++;
	try {
		std::vector<unsigned int> a;
		a = PmergeMe<unsigned int, std::vector>::createInput(av);
		print(a);
		PmergeMe<unsigned int, std::vector>		v(a.begin(), a.end());
		v.sort();
		std::cout << HYEL "after: " << v << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
