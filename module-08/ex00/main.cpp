/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:37:01 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/16 01:26:27 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() {
    std::list<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

    int valueToFind = 30;

    try {
        easyfind(v, valueToFind);
        std::cout << HGRN "Value " << valueToFind << " found in vector." reset << std::endl;
    } catch (const std::exception& e) {
        std::cerr << HRED "Exception: " << e.what() << reset << std::endl;
    }

    valueToFind = 31;

    try {
        easyfind(v, valueToFind);
        std::cout << HGRN "Value " << valueToFind << " found in vector." reset << std::endl;
    } catch (const std::exception& e) {
        std::cerr << HRED "Exception: " << e.what() << reset << std::endl;
    }

    valueToFind = 50;

    try {
        easyfind(v, valueToFind);
        std::cout << HGRN "Value " << valueToFind << " found in vector." reset << std::endl;
    } catch (const std::exception& e) {
        std::cerr << HRED "Exception: " << e.what() << reset << std::endl;
    }

    valueToFind = 51;

    try {
        easyfind(v, valueToFind);
        std::cout << HGRN "Value " << valueToFind << " found in vector." reset << std::endl;
    } catch (const std::exception& e) {
        std::cerr << HRED "Exception: " << e.what() << reset << std::endl;
    }
    return 0;
}