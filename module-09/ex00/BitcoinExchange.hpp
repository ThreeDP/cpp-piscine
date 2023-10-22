/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:27:32 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/22 10:21:27 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BITCOIN_EXCHANGE_HPP__
# define __BITCOIN_EXCHANGE_HPP__
# include "define.hpp"
# include <map>
# include <iterator>
# include <vector>
# include <fstream>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <ctime>

class BitcoinExchange
{	
	public:
		BitcoinExchange(std::string fileName);
		BitcoinExchange(const BitcoinExchange &bit);
		BitcoinExchange &operator=(const BitcoinExchange &bit);
		~BitcoinExchange();
		
		void			startProcess(void);
	
		class Mydate : public std::tm {
			public:
				Mydate(void);
				~Mydate(void);
				Mydate(const Mydate &date);
				Mydate	&operator=(const Mydate &date);
				bool	operator==(const Mydate &date);
				bool	operator>(Mydate const &date) const;
				bool	operator<(Mydate const &date) const;
		};

		typedef struct s_date {
			std::string	year;
			std::string	month;
			std::string	day;
			std::string	strRate;
			Mydate		date;
			float		rate;
		}				t_date;

		void			convertToDate(t_date &d);
		void			isFormatValid(std::istream &is, t_date &d, char delimiter, std::string line);
		void			isValidDate(t_date &d);
		bool			isLeapYear(int year);

		class Except: virtual public std::exception {
			protected:
			std::string error_message;
			public:
				explicit Except(const std::string& msg) : error_message(msg) {}
				virtual ~Except() throw () {}
				virtual const char* what() const throw () { return error_message.c_str();}
		};

		const std::string getErrorMsg(void) const;
		const std::string getFileName(void) const;
		const std::map<Mydate, float> &getDB(void) const;

		private:
			std::string					_errorMsg;
			std::string 				_fileName;
			std::map<Mydate, float>		_db;
			BitcoinExchange(void) {}
			void	loadDB(void);
			void	execConversion(void);
			void	printConversion(std::istringstream &isLine, std::string line);
};

#endif


