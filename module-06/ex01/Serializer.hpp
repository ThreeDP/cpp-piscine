/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:19:56 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/10 12:55:05 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SERIALIZER_HPP__
# define __SERIALIZER_HPP__

#include <iostream>
#include <stdint.h>
#include "data.h"
#include "define.hpp"

class Serializer {
	public:
		Serializer(void);
		~Serializer(void);
		Serializer(const Serializer &s);
		Serializer &operator=(const Serializer &s);
	
		static uintptr_t	serialize(Data *ptr);
		static Data*		deserialize(uintptr_t raw);	
};

#endif 