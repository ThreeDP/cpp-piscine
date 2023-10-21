/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:27:32 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/21 19:48:41 by dapaulin         ###   ########.fr       */
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
				Mydate(void){
					this->tm_gmtoff = 0;
					this->tm_hour = 0;
					this->tm_isdst = 0;
					this->tm_mday = 0;
					this->tm_min = 0;
					this->tm_mon = 0;
					this->tm_sec = 0;
					this->tm_wday = 0;
					this->tm_yday = 0;
					this->tm_year = 0;
					this->tm_zone = 0;
				}
				Mydate(const Mydate &date) {
					*this = date;
				}
				Mydate	&operator=(const Mydate &date) {
					this->tm_year = date.tm_year;
					this->tm_mon = date.tm_mon;
					this->tm_mday = date.tm_mday;
					return *this;
				}
				bool	operator==(const Mydate &date) const {
					return (this->tm_mday == date.tm_mday && this->tm_mon == date.tm_mon && this->tm_year == date.tm_year);
				}

				bool	operator>(Mydate const &date) const {
					if (this->tm_year != date.tm_year) {
						return this->tm_year > date.tm_year;
					}
					if (this->tm_mon != date.tm_mon) {
						return this->tm_mon > date.tm_mon;
					}
					return this->tm_mday > date.tm_mday;
				}

				bool	operator<(Mydate const &date) const {
					if (this->tm_year != date.tm_year) {
						return this->tm_year < date.tm_year;
					}
					if (this->tm_mon != date.tm_mon) {
						return this->tm_mon < date.tm_mon;
					}
					return this->tm_mday < date.tm_mday;
				}

				friend std::ostream &operator<<(std::ostream &os, const Mydate &date) {
					os << HMAG << date.tm_year << "-" << date.tm_mon << "-" << date.tm_mday << reset;
					return os;
				}
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
				virtual const char* what() const throw () {
					return error_message.c_str();
				}
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


