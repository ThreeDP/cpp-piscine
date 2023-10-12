/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:38:22 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/12 14:51:32 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main() {
	int a[] = {1, 2, 3, 4};
	float b[] = {2.5, 3.7, 99.5, 10.3};

	std::cout << REDHB "[           INT           ]" reset << std::endl;
	::printArray<int>(a, 4);
	::iter<int>(a, 4, ::plus);
	::printArray<int>(a, 4);
	std::cout << std::endl << REDHB "[           FLOAT           ]" reset << std::endl;
	::printArray<float>(b, 4);
	::iter<float>(b, 4, ::plus);
	::printArray<float>(b, 4);
}