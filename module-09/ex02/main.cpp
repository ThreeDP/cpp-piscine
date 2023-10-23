/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:28:31 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/23 14:35:29 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

void	print(std::vector<unsigned int> &a) {
	std::cout << HYEL << std::setw(15) << std::left << "before: " reset;
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
		std::clock_t	vTime = clock();
		PmergeMe<unsigned int, std::vector>		v(a.begin(), a.end());
		v.sort();
		vTime = clock() - vTime;
		std::list<unsigned int> b;
		b = PmergeMe<unsigned int, std::list>::createInput(av);
		std::clock_t	lTime = clock();
		PmergeMe<unsigned int, std::list>		l(b.begin(), b.end());
		l.sort();
		lTime = clock() - lTime;
		std::cout << HYEL << std::setw(15) << std::left << "after: " reset <<  HGRN << v << reset << std::endl;
		std::cout << HWHT << "Time to process a range of " << HMAG << a.size() << HWHT " elements with std::" << HGRN << v << HWHT ": " HBLU << std::fixed << static_cast<double>(vTime) / CLOCKS_PER_SEC << HWHT " us" << std::endl;
		std::cout << HWHT << "Time to process a range of " << HMAG << b.size() << HWHT " elements with std::" << HGRN << l << HWHT ": " HBLU << std::fixed << static_cast<double>(lTime) / CLOCKS_PER_SEC << HWHT " us" << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
