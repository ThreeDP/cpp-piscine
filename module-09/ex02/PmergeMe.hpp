/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:15:58 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/23 11:44:47 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PMERGE_ME_HPP__
# define __PMERGE_ME_HPP__

# include "define.hpp"
# include <sstream>
# include <iostream>
# include <iomanip>
# include <algorithm>
# include <list>
# include <vector>

template <typename T, template <typename, typename> class C>
class PmergeMe {
	
	const static int 						_jacobsthalSequence[21];
	C<T, std::allocator<T> >				_arr;
	std::vector<C<T, std::allocator<T > > >	_pairs;
	int										_remainder;
	int										_listSize;
	PmergeMe(void){}
	
	public:
		PmergeMe(typename C<T, std::allocator<T> >::iterator start, typename C<T, std::allocator<T> >::iterator end);
		~PmergeMe(void);
		PmergeMe(const PmergeMe<T, C > &pm);
		PmergeMe<T, C>	&operator=(const PmergeMe<T, C > &pm);
		
		static int						arrySize(char **av);
		const C<T, std::allocator<T> >	&getArr(void) const;
		static C<T, std::allocator<T> >	createInput(char **av);

		void							sort(void);
		void							makePairs(void);
		void							orderPairs(void);
		void							binaryInsertion(unsigned int num);
		void							sortAlgorithm(void);

		class errorPmergeMe : public std::exception {
			public:
				const char * what() const throw() {
					return HRED "Error" reset;
				}
		};
};

template <typename T, template <typename, typename> class C>
std::ostream &operator<<(std::ostream &os, PmergeMe<T, C > const &pm) {
	C<T, std::allocator<T> >				a = pm.getArr();
	os << "[ ";
	for (typename C<T, std::allocator<T> >::iterator it = a.begin(); it != a.end(); ++it) {
		os << *it << " ";
	}
	os << "]";
	return os;
}

template <typename T, template <typename, typename> class C>
const int PmergeMe<T, C>::_jacobsthalSequence[21] = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};

template <typename T, template <typename, typename> class C>
PmergeMe<T, C>::PmergeMe(typename C<T, std::allocator<T> >::iterator start, typename C<T, std::allocator<T> >::iterator end) : _arr(start, end), _remainder(-1), _listSize(0) {
	
}

template <typename T, template <typename, typename> class C>
PmergeMe<T, C>::~PmergeMe(void) {
	
}

template <typename T, template <typename, typename> class C>
PmergeMe<T, C>::PmergeMe(const PmergeMe<T, C > &pm) {
	*this = pm;
}

template <typename T, template <typename, typename> class C>
PmergeMe<T, C >	&PmergeMe<T, C >::operator=(const PmergeMe<T, C > &pm) {
	if (this != &pm) {
		this->_arr = pm.getArr();
	}
	return *this;
}

template <typename T, template <typename, typename> class C>
int PmergeMe<T, C>::arrySize(char **av) {
	int i = 0;
	while (av[i]) {
		i++;
	}
	return (i);
}

template <typename T, template <typename, typename> class C>
const C<T , std::allocator<T> > &PmergeMe<T, C>::getArr(void) const {
    return this->_arr;
}

template <typename T, template <typename, typename> class C>
void	PmergeMe<T, C>::sort(void) {
	if (this->_arr.size() == 1) {
		return ;
	}
	this->makePairs();
	this->orderPairs();
	// for (int i = 1; i < 13; i++) {
	// 	if (i % 2 == 0) {
	// 		this->binaryInsertion(i / (2 * 3));
	// 		std::cout << i / (2 * 3) << " ";
	// 	} else {
	// 		std::cout << (i * 2) / 3 << " ";
	// 		this->binaryInsertion((i * 2) / 3);
	// 	}
	// }
	// std::cout << std::endl;
	this->sortAlgorithm();
}

template <typename T, template <typename, typename> class C>
C<T, std::allocator<T> >	PmergeMe<T, C >::createInput(char **av) {
	C<T, std::allocator<T> >		array;
	int 							size = arrySize(av);

	size--;
	for (; size >= 0; size--) {
		int	num = 0;
		std::istringstream is(av[size]);
		is >> num;
		if (!is) {
			throw errorPmergeMe();
		}
		if (num > 2147483647 || num < -2147483648) {
			throw errorPmergeMe();
		}
		array.push_back(num);
	}
	if (array.size() >= 349526)
		throw errorPmergeMe();
	return array;
}

template <typename T, template <typename, typename> class C>
void	PmergeMe<T, C>::makePairs(void) {
	while (this->_arr.size() >= 2) {
		C<T, std::allocator<T> > pt;
		pt.push_back(this->_arr.back());
		this->_arr.pop_back();
		pt.push_back(this->_arr.back());
		this->_arr.pop_back();
		std::sort(pt.rbegin(), pt.rend());
		this->_pairs.push_back(pt);
	}
	this->_listSize = this->_pairs.size() * 2;
	if (this->_arr.size() == 1) {
		this->_remainder = this->_arr.back();
		this->_arr.pop_back();
	}
	{
		/* ISSO AQUI É SÓ VISUALIZAÇÃO */
		for (typename std::vector<C<T, std::allocator<T> > >::iterator it = this->_pairs.begin(); it != this->_pairs.end(); ++it) {
			std::cout << "[ ";
			std::cout << (*it)[0] << " ";
			std::cout << (*it)[1];
			std::cout << " ]" << std::endl;
		}
		if (this->_remainder >= 0) {
			std::cout << "remainder: " << _remainder << std::endl;
		}
	}
}

template <typename T, template <typename, typename> class C>
void				PmergeMe<T, C>::orderPairs(void) {
	for (typename std::vector<C<T, std::allocator<T> > >::iterator it = this->_pairs.begin() + 1; it != this->_pairs.end(); ++it) {
		for (typename std::vector<C<T, std::allocator<T> > >::iterator cursor = this->_pairs.begin(); cursor != this->_pairs.end(); ++cursor) {
			if (*it < *cursor) {
				(*it).swap(*cursor);
			}
		}
	}

	{
		/* ISSO AQUI É SÓ VISUALIZAÇÃO */
		for (typename std::vector<C<T, std::allocator<T> > >::iterator it = this->_pairs.begin(); it != this->_pairs.end(); ++it) {
			std::cout << "[ ";
			std::cout << (*it)[0] << " ";
			std::cout << (*it)[1];
			std::cout << " ]" << std::endl;
		}
		if (this->_remainder >= 0) {
			std::cout << "remainder: " << _remainder << std::endl;
		}
	}
}

template <typename T, template <typename, typename> class C>
void	PmergeMe<T, C>::sortAlgorithm(void) {
	bool		codeExit = false;
	for (typename std::vector<C<T, std::allocator<T> > >::iterator it = this->_pairs.begin(); it != this->_pairs.end(); ++it) {
			this->binaryInsertion(it->back());
			it->pop_back();
	}
	for (int jacobIndex = 0; jacobIndex < 70; jacobIndex++) {
		int i;
		if (this->_jacobsthalSequence[jacobIndex] < this->_listSize) {
			i = this->_jacobsthalSequence[jacobIndex];
		} else {
			i = this->_listSize;
			codeExit = true;
		}
		for (typename std::vector<C<T, std::allocator<T> > >::reverse_iterator it = this->_pairs.rbegin() + (i / 2); it != this->_pairs.rend(); ++it) {
			if (it->empty())
				break ;
			this->binaryInsertion(it->back());
			it->pop_back();
		}
		if (codeExit)
			break ;
	}
	if (this->_remainder != -1) {
		this->binaryInsertion(this->_remainder);	
	}
}

// template <typename T, template <typename, typename> class C>
// void	PmergeMe<T, C>::binaryInsertion(unsigned int num) {
// 	for (typename C<T, std::allocator<T> >::reverse_iterator it = this->_arr.rbegin(); it != this->_arr.rend(); ++it) {
// 		if (*it > num) {
// 			continue ;
// 		}
// 		else {
// 			C<T, std::allocator<T> > slice1.erase(this->_arr.begin(), it);
// 			slice1.push_back(num);
// 			C<T, std::allocator<T> > slice2.erase(it, this_arr.end());
// 			this->_arr.insert(slice1.end(), slice2.begin(), slice2.end());
// 		}
// 	}
// }

template <typename T, template <typename, typename> class C>
void PmergeMe<T, C>::binaryInsertion(unsigned int num) {
    typename C<T, std::allocator<T> >::reverse_iterator it = this->_arr.rbegin();
    for (; it != this->_arr.rend(); ++it) {
        if (*it > num) {
            continue;
        } else {
            C<T, std::allocator<T> > slice1(this->_arr.begin(), it.base());
            slice1.push_back(num);
            C<T, std::allocator<T> > slice2(it.base(), this->_arr.end());
            this->_arr.clear();
            this->_arr.insert(this->_arr.end(), slice1.begin(), slice1.end());
            this->_arr.insert(this->_arr.end(), slice2.begin(), slice2.end());
            return;
        }
    }
    // If num is smaller than all elements, just push it to the beginning
    this->_arr.push_back(num);
}


#endif