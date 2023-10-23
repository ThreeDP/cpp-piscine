/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:15:58 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/22 23:34:56 by dapaulin         ###   ########.fr       */
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
	T										_remainder;
	int										_listSize;
	PmergeMe(void){}
	public:
		~PmergeMe(void) {};
		PmergeMe(const PmergeMe<T, C > &pm) : _arr(pm.getArr(), _remainder(-1)) {};
		PmergeMe<T, C>	&operator=(const PmergeMe<T, C > &pm);
		// PmergeMe<T, C >	&operator=(const PmergeMe<T, C > &pm) {
		// 	if (this != &pm) {
		// 		this->_arr = pm.getArr();
		// 	}
		// 	return *this;
		// }
		PmergeMe(typename C<T, std::allocator<T> >::iterator start, typename C<T, std::allocator<T> >::iterator end) : _arr(start, end), _remainder(-1), _listSize(0) {}
		static int arrySize(char **av) {
			int i = 0;
			while (av[i]) {
				i++;
			}
			return (i);
		}
		
		const C<T, std::allocator<T> >	&getArr(void) const;
		// const C<T , std::allocator<T> > &getArr(void) const {
		// 	return this->_arr;
		// }
		static C<T, std::allocator<T> >	createInput(char **av) {
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

		void							sort(void) {
			if (this->_arr.size() == 1) {
				return ;
			}
			this->makePairs();
			this->orderPairs();
			this->sortAlgorithm();
		}
		
		void							makePairs(void) {
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

		void				orderPairs(void) {
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

		void							sortAlgorithm(void) {
			bool		codeExit = false;
			for (int jacobIndex = 0; jacobIndex < 6; jacobIndex++) {
				int i;
				if (this->_jacobsthalSequence[jacobIndex] < this->_listSize) {
					i = this->_jacobsthalSequence[jacobIndex];
				} else {
					i = this->_listSize;
					codeExit = true;
				}
				for (typename std::vector<C<T, std::allocator<T> > >::reverse_iterator it = this->_pairs.rbegin() + (i / 2); it != this->_pairs.rend(); ++it) {
					std::cout << (*it)[i % 2] << " ";
				}
				std::cout << std::endl;
				if (codeExit)
					return ;
			}
		}

		class errorPmergeMe : public std::exception {
			public:
				const char * what() const throw() {
					return HRED "Error" reset;
				}
		};

		//template <typename T, template <typename, typename> class C>
		friend std::ostream &operator<<(std::ostream &os, PmergeMe<T, C > const &pm) {
			C<T, std::allocator<T> >				a = pm.getArr();
			os << "[ ";
			for (typename C<T, std::allocator<T> >::iterator it = a.begin(); it != a.end(); ++it) {
				os << *it << " ";
			}
			os << "]";
			return os;
		}
};

template <typename T, template <typename, typename> class C>
const int PmergeMe<T, C>::_jacobsthalSequence[21] = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};

template <typename T, template <typename, typename> class C>
PmergeMe<T, C >	&PmergeMe<T, C >::operator=(const PmergeMe<T, C > &pm) {
	if (this != &pm) {
		this->_arr = pm.getArr();
	}
	return *this;
}

template <typename T, template <typename, typename> class C>
const C<T , std::allocator<T> > &PmergeMe<T, C>::getArr(void) const {
    return this->_arr;
}

template <typename T, template <typename, typename> class C>
void	PmergeMe<T, C>::sortAlgorithm(void) {
	bool		codeExit = false;
	for (int jacobIndex = 0; jacobIndex < 6; jacobIndex++) {
		int i;
		if (this->_jacobsthalSequence[jacobIndex] < this->_listSize) {
			i = this->_jacobsthalSequence[jacobIndex];
		} else {
			i = this->_listSize;
			codeExit = true;
		}
		for (typename std::vector<C<T, std::allocator<T> > >::reverse_iterator it = this->_pairs.rbegin() + (i / 2); it != this->_pairs.rend(); ++it) {
			std::cout << (*it)[i % 2] << " ";
		}
		std::cout << std::endl;
		if (codeExit)
			return ;
	}
}




// C<T >	PmergeMecreateInput(char **av) {
// 	C<T >		array;

// 	for (int i = 0; av[i]; i++) {
// 		long int	num = 0;
// 		std::istringstream is(av[i]);
// 		is >> num;
// 		if (!is) {
// 			std::cout << "is not a Number" << std::endl;
// 			return ;
// 			/*Error*/
// 		}
// 		if (num > 2147483647 || num < -2147483648) {
// 			std::cout << "Max or Min Int" << std::endl;
// 			return ();
// 			/*Error*/
// 		}
// 		array.push_back(num);
// 	}
// 	return array;
// }

#endif