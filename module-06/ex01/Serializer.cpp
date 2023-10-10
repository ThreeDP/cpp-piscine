/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:30:44 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/10 13:08:43 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) {
	std::cout << GRNHB "[ Serializer Converter Constructor ]" reset << std::endl;
}

Serializer::~Serializer(void) {
	std::cout << REDHB "[ Serializer Converter Destructor ]" reset << std::endl;
}

Serializer::Serializer(Serializer const &s) {
	std::cout << YELHB "[ Serializer Converter Copy Constructor ]" reset << std::endl;
	(void)s;
}

Serializer &Serializer::operator=(Serializer const &s) {
	std::cout << BLUHB "[ Serializer Converter Assigment Operator ]" reset << std::endl;
	(void)s;
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr) {
	uintptr_t res;
	res = reinterpret_cast<uintptr_t >(ptr);
	std::cout << CYNHB "[ Serialize " << ptr << " to " << res << " ]" reset << std::endl;
	return res;
}

Data*	Serializer::deserialize(uintptr_t raw) {
	Data *res;
	res = reinterpret_cast<Data *>(raw);
	std::cout << MAGHB "[ deserialize " << raw << " to " << res << " ]" reset << std::endl;
	return res;
}