/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:51:45 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/23 14:28:40 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(const std::string f, std::string s1, std::string s2) : fileName(f){
	this->findString = s1;
	this->replaceString = s2;
}

Replace::~Replace(void) {
	return ;
}

int	Replace::getTextInFile(void) {
	std::ifstream			ifs;
	const std::streamsize	bufferSize = __BUFFER_SIZE__;
	char					buffer[__BUFFER_SIZE__];

	ifs.open(this->fileName.c_str(), std::ifstream::in);
	if (!ifs)
	{
		std::cerr << "Look the file: " << this->fileName << "! They look me wrong..." << std::endl;
		std::exit(1);
	}
	while (ifs.get(buffer, bufferSize, '\0'))
		this->inString += buffer;
	ifs.close();
	return (0);
}

void	Replace::alterTextInFile(void) {
	std::string::size_type find;
	std::string::size_type start;

	start = 0;
	find = this->inString.find(this->findString);
	while (find != std::string::npos) {
		this->outString += this->inString.substr(0, find);
		this->outString += this->replaceString;
		start = find + this->findString.size();
		this->inString = this->inString.substr(start, this->inString.size());
		find = this->inString.find(this->findString);
	}
	if (this->inString.size() > 0)
		this->outString += this->inString;
}

int	Replace::setTextInFile(void) {
	std::string		outFile = this->fileName + ".replace";
	std::ofstream			ofs;
	
	ofs.open(outFile.c_str(), std::ifstream::out);
	if (!ofs)
	{
		std::cerr << "Look the file: " << this->fileName << ".replace! They look me wrong..." << std::endl;
		std::exit(1);
	}
	ofs << this->outString;
	ofs.close();
	return (0);
}

std::string	Replace::replace(void) {
	this->getTextInFile();
	this->alterTextInFile();
	this->setTextInFile();
	return (this->outString);
}