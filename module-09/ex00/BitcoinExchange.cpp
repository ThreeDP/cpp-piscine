/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:37:32 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/22 10:22:33 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string fileName) : _errorMsg(""), _fileName(fileName) {
	std::cout << HGRN "Bitcoin Constructor" reset << std::endl;
}

BitcoinExchange::~BitcoinExchange(void) {
	std::cout << HRED "Bitcoin Destructor" reset << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &bit) {
	*this = bit;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &bit) {
	this->_errorMsg = bit.getErrorMsg();
	this->_fileName = bit.getFileName();
	this->_db = bit.getDB();
	return *this;
}

const std::string BitcoinExchange::getErrorMsg(void) const {
	return this->_errorMsg;
}

const std::string BitcoinExchange::getFileName(void) const {
	return this->_fileName;	
}

const std::map<BitcoinExchange::Mydate, float> &BitcoinExchange::getDB(void) const {
	return this->_db;
}

void	BitcoinExchange::loadDB(void) {
	std::string header;
	std::ifstream file("data.csv");
	if (!file) {
		this->_errorMsg = HRED "Error: " HYEL "could not open file." reset;
		throw (Except(this->_errorMsg));
	}
	std::getline(file, header);
	if (header != "date,exchange_rate") {
		this->_errorMsg = HRED "Error: " HYEL "header don't expected." reset;
		throw (Except(this->_errorMsg));
	}
	std::string line;
	std::getline(file, line);
	while (file) {
		std::istringstream isLine(line);
		t_date		d;
		d.date = Mydate();
		this->isFormatValid(isLine, d, ',', line);
		this->convertToDate(d);
		this->isValidDate(d);
		this->_db[d.date] = d.rate;
		std::getline(file, line);
	}
	file.close();
}

void	BitcoinExchange::printConversion(std::istringstream &isLine, std::string line){
	try {
		t_date		d;
		d.date = Mydate();
		this->isFormatValid(isLine, d, '|', line);
		this->convertToDate(d);
		this->isValidDate(d);
		if (d.rate < 0) {
			this->_errorMsg = HRED "Error: " HYEL "not a positive number." reset;
			throw (Except(this->_errorMsg));
		} else if (d.rate > 2147483647.0 || d.rate < -2147483648.0) {
			this->_errorMsg = HRED "Error: " HYEL "too large a number." reset;
			throw (Except(this->_errorMsg));
		}
		while (true) {
			std::map<Mydate, float>::iterator it = this->_db.find(d.date);
			if (it != this->_db.end()) {
				std::cout << HGRN << d.date.tm_year << "-" << d.date.tm_mon << "-" << d.date.tm_mday << HWHT " => " HBLU << std::fixed << std::setprecision(2) << d.rate << HWHT " = " HBLU << d.rate * it->second << reset << std::endl;
				break ;
			}
			d.date.tm_mday--;
			mktime(&d.date);
		}
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void	BitcoinExchange::execConversion(void) {
	std::string header;
	std::ifstream file(this->_fileName.c_str());
	if (!file) {
		this->_errorMsg = HRED "Error: " HYEL "could not open file." reset;
		throw (Except(this->_errorMsg));
	}
	try {
		std::getline(file, header);
		if (header != "date | value") {
			this->_errorMsg = HRED "Error: " HYEL "header don't expected." reset;
			throw (Except(this->_errorMsg));
		}
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
		return ;
	}
	std::string line;
	std::getline(file, line);
	while (file) {
		std::istringstream	isLine(line);
		this->printConversion(isLine, line);
		std::getline(file, line);
	}
	file.close();
}

void	BitcoinExchange::startProcess(void) {
	try {
		this->loadDB();
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	this->execConversion();
}

void BitcoinExchange::isFormatValid(std::istream &is, t_date &d, char delimiter, std::string line) {
	std::getline(is, d.year, '-');
	if (!is) {
		this->_errorMsg = HRED "Error: bad input => " HYEL + line + reset;
		throw (Except(this->_errorMsg));
	}
	std::getline(is, d.month, '-');
	if (!is) {
		this->_errorMsg = HRED "Error: bad input => " HYEL + line + reset;
		throw (Except(this->_errorMsg));
	}
	std::getline(is, d.day, delimiter);
	if (!is) {
		this->_errorMsg = HRED "Error: bad input => " HYEL + line + reset;
		throw (Except(this->_errorMsg));
	}
	std::getline(is, d.strRate);
	if (!is) {
		this->_errorMsg = HRED "Error: bad input => " HYEL + line + reset;
		throw (Except(this->_errorMsg));
	}
}

void BitcoinExchange::convertToDate(t_date &d) {
	int month_tmp = 0;
	std::istringstream isY(d.year);
	std::istringstream isM(d.month);
	std::istringstream isD(d.day);
	std::istringstream isR(d.strRate);
	
	isY >> d.date.tm_year;
	isM >> month_tmp;
	d.date.tm_mon = month_tmp - 1;
	isD >> d.date.tm_mday;
	isR >> d.rate;
	if (!isY) {
		this->_errorMsg = HRED "Error: bad input => " HYEL + d.year + HRED "-" + d.month + "-" + d.day + reset;
		throw (Except(this->_errorMsg));
	} else if (!isM) {
		this->_errorMsg = HRED "Error: bad input => " + d.year + "-" HYEL + d.month + HRED "-" + d.day + reset;
		throw (Except(this->_errorMsg));
	} else if (!isD) {
		this->_errorMsg = HRED "Error: bad input => " + d.year + "-" + d.month + "-" HYEL + d.day + reset;
		throw (Except(this->_errorMsg));
	} else if (!isR) {
		this->_errorMsg = HRED "Error: bad input => " HYEL + d.strRate + reset;
		throw (Except(this->_errorMsg));
	}
}

bool BitcoinExchange::isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

void BitcoinExchange::isValidDate(t_date &d) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
    if (d.date.tm_year < 0 || ( 1 + d.date.tm_mon) < 1 || ( 1 + d.date.tm_mon) > 12 || d.date.tm_mday < 1) {
        this->_errorMsg = HRED "Error: Invalid date => " HYEL + d.year + "-" + d.month + "-" + d.day + reset;
		throw (Except(this->_errorMsg));
    }
    if (isLeapYear(d.date.tm_year)) {
        daysInMonth[1] = 29;
    }
    if (d.date.tm_mday > daysInMonth[d.date.tm_mon]) {
        this->_errorMsg = HRED "Error: bad input => " HYEL + d.year + "-" + d.month + "-" + d.day + reset;
		throw (Except(this->_errorMsg));
    }
}

BitcoinExchange::Mydate::Mydate(void) {
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

BitcoinExchange::Mydate::~Mydate(void) {
	
}

BitcoinExchange::Mydate::Mydate(const Mydate &date) {
	*this = date;
}

BitcoinExchange::Mydate	&BitcoinExchange::Mydate::operator=(const Mydate &date) {
	this->tm_year = date.tm_year;
	this->tm_mon = date.tm_mon;
	this->tm_mday = date.tm_mday;
	return *this;
}

bool BitcoinExchange::Mydate::operator==(const Mydate &date) {
	return (this->tm_mday == date.tm_mday && this->tm_mon == date.tm_mon && this->tm_year == date.tm_year);
}

bool BitcoinExchange::Mydate::operator>(Mydate const &date) const {
	if (this->tm_year != date.tm_year) {
		return this->tm_year > date.tm_year;
	}
	if (this->tm_mon != date.tm_mon) {
		return this->tm_mon > date.tm_mon;
	}
	return this->tm_mday > date.tm_mday;
}

bool	BitcoinExchange::Mydate::operator<(Mydate const &date) const {
	if (this->tm_year != date.tm_year) {
		return this->tm_year < date.tm_year;
	}
	if (this->tm_mon != date.tm_mon) {
		return this->tm_mon < date.tm_mon;
	}
	return this->tm_mday < date.tm_mday;
}