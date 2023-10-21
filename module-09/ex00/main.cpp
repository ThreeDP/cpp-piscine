/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:39:52 by dapaulin          #+#    #+#             */
/*   Updated: 2023/10/20 21:54:39 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
// #include <iostream>
// #include <fstream>
// #include <string>
// #include <cstring>
// #include <vector>
// #include <iomanip>
// #include <sstream>
// #include <ctime>

// bool parseDate(const std::string& str, std::tm& date) {
// 	char format[] = "%Y-%m-%d";
// 	std::memset(&date, 0, sizeof(date));  // Inicialize a estrutura tm

// 	if (strptime(str.c_str(), format, &date) == NULL) {
// 		return false; // Falha na análise da data
// 	}

// 	return true;
// }

// struct info_type {
//     std::tm		_date;
// 	std::time_t	_time;
// 	float		_rate;


	
//     friend std::istream& operator>>(std::istream& is, info_type& info) {
// 		std::string	year;
// 		std::string	month;
// 		int	m;
// 		std::string	day;
// 		std::string	rate;
// 		// if (i == 0) {
// 		// 	std::getline(is, line, ',');
// 		// 	if (line == "date") {
// 		// 		return is;
// 		// 	}
// 		// }
//         // is >> std::ws;
//         std::getline(is, year, '-');
// 		std::getline(is, month, '-');
// 		std::getline(is, day, ',');
// 		std::getline(is, rate);
// 		// 	std::cout << "Format Error!" << std::endl;
// 		// 	return is;
// 		// }

// 		std::istringstream iy(year);
// 		std::istringstream im(month);
// 		std::istringstream id(day);
// 		std::istringstream ir(rate);
// 		// if (!id) {
// 		// 	std::cout << "Error convert day!" << std::endl;
// 		// }
// 		// if (!im) {
// 		// 	std::cout << "Error convert month!" << std::endl;
// 		// }
// 		// if (!iy) {
// 		// 	std::cout << "Error convert year!" << std::endl;
// 		// }
// 		// if (!iy) {
// 		// 	std::cout << "Error convert rate!" << std::endl;
// 		// }
// 		id >> info._date.tm_mday;
// 		im >> m;
// 		info._date.tm_mon = m - 1;
// 		iy >> info._date.tm_year;
// 		ir >> info._rate;
// 		std::cout << info._date.tm_year << "'-'" << info._date.tm_mon << "'-'" << info._date.tm_mday << std::endl;
// 		info._date.tm_mday++;
// 		std::mktime(&info._date);
// 		std::cout << info._date.tm_year << "'-'" << info._date.tm_mon << "'-'" << info._date.tm_mday << std::endl;
// 		// std::istringstream date_stream(info._date);
// 		// std::istringstream(info._rate);
//         return is;
//     }
// };

// void func4() {
//     std::ifstream file("data.csv");
//     std::vector<info_type> v;

//     for (info_type info; file >> info;) { // keep reading until we run out
//         // we only get here if the read succeeded
//         v.push_back(info);
// 		break ;
//     }

//     for (std::vector<info_type>::const_iterator it = v.begin(); it != v.end(); ++it) {
//         const info_type& info = *it;
// 		std::cout << " date: " << info._date.tm_year << "-" << info._date.tm_mon << "-" << info._date.tm_mday << "\t";
// 		//std::cout << " date: " << info._date.tm_year + 1900 << "-" << info._date.tm_mon + 1 << "-" << info._date.tm_mday << "\t";
//         std::cout << "rate: " << info._rate << std::endl;
// 		break ;
//     }
// }

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout <<HRED "Error: " HYEL "could not open file." reset;
		return (1);
	}
	BitcoinExchange b(av[1]);
	b.startProcess();
    return 0;
}