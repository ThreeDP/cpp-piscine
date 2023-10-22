/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:53:54 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/13 20:27:23 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ARRAY__HPP__
# define __ARRAY__HPP__

# include <iostream>
# include "define.hpp"

template<typename T>
class Array {
	private:
		unsigned int	_size;
		T				*_array;

	public:
		Array(void);
		Array(unsigned int n);
		~Array(void);
		Array(const Array &a);
		Array &operator=(const Array &a);

		class outOfRange : public std::exception {
			public:
				const char *what(void) const throw();
		};

		T &operator[](unsigned int i);

		T &operator[](unsigned int i) const;
		void			print(void);

		unsigned int	size(void) const;
		void			setMem(T v);
};

template <typename T>
void	Array<T>::setMem(T v) {
	for (unsigned int i = 0; i < _size; i++) {
		_array[i] = v;
	}
}

template <typename T>
Array<T>::Array(void) : _size(1), _array(NULL) {
	this->_array = new T[this->_size];
	this->setMem(0);
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n) {
	this->_array = new T[this->_size];
	this->setMem(0);
}

template <typename T>
Array<T>::~Array(void) {
	delete [] this->_array;
}

template <typename T>
Array<T>::Array(const Array<T> &a) : _size(1), _array(NULL) {
	*this = a;
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array<T> &a) {
	this->_size = a.size();
	this->_array = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++) {
		this->_array[i] = a[i];
	}
	return *this;
}

template <typename T>
unsigned int Array<T>::size(void) const {
	return Array<T>::_size;
}

template <typename T>
const char *Array<T>::outOfRange::what(void) const throw() {
	return (HRED "Array out of range." reset);
}

template <typename T>
T	&Array<T>::operator[](unsigned int i) const {
	if (i >= Array<T>::_size) {
		throw outOfRange();
		return this->_array[0];
	}
	return this->_array[i];
}

template <typename T>
T	&Array<T>::operator[](unsigned int i) {
	if (i >= Array<T>::_size) {
		throw outOfRange();
		return this->_array[0];
	}
	return this->_array[i];
}

template<typename T>
void	Array<T>::print(void) {
	std::cout << HGRN "[ ";
	for (unsigned int i = 0; i < _size; i++) {
		if (i == _size - 1) {
			std::cout << this->_array[i] << " ]" reset << std::endl; 
		} else {
			std::cout << this->_array[i] << ", "; 
		}
	}
}

#endif 