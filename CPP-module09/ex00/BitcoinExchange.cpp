#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange() { }

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
	: _database(other._database) { }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_database = other._database;
	return *this;
}

BitcoinExchange::~BitcoinExchange() { }

std::string BitcoinExchange::trim(const std::string &str) const
{
	size_t start = str.find_first_not_of(" \t\r\n");
	if (start == std::string::npos)
		return "";
	size_t end = str.find_last_not_of(" \t\r\n");
	return str.substr(start, end - start + 1);
}

bool BitcoinExchange::isLeapYear(int year) const
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	for (size_t i = 0; i < date.size(); ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (date[i] < '0' || date[i] > '9')
			return false;
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 1 || month < 1 || month > 12 || day < 1)
		return false;

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (isLeapYear(year))
		daysInMonth[1] = 29;

	return day <= daysInMonth[month - 1];
}

bool BitcoinExchange::parseValue(const std::string &str, double &out) const
{
	if (str.empty())
		return false;

	std::stringstream ss(str);
	ss >> out;// read string mijic - pahir out-i mej double typeov;
	if (ss.fail() || !ss.eof())
		return false;
	return true;
}

void BitcoinExchange::LoadDataBase(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		line = trim(line);
		if (line.empty())
			continue;

		size_t storaket = line.find(',');
		if (storaket == std::string::npos)
			continue;

		std::string date = trim(line.substr(0, storaket));
		std::string price_str = trim(line.substr(storaket + 1));
		double price = 0.0;

		if (!isValidDate(date) || !parseValue(price_str, price))
			continue;

		_database[date] = price;
	}
}

double BitcoinExchange::findRate(const std::string &date) const
{
	std::map<std::string, double>::const_iterator it = _database.lower_bound(date);

	if (it != _database.end() && it->first == date)
		return it->second;

	if (it == _database.begin())
		return -1;

	--it;
	return it->second;
}

bool BitcoinExchange::processLine(const std::string &line)
{
    size_t pipe = line.find('|');

    if (pipe == std::string::npos)
    {
        std::cout << RED << "Error: bad input => " << line << RESET << std::endl;
        return false;
    }

    std::string date = trim(line.substr(0, pipe));
    std::string value_atr = trim(line.substr(pipe + 1));
    double value = 0.0;

    if (!isValidDate(date)) {
        std::cout << RED << "Error: bad input => " << line << RESET << std::endl;
        return false;
    }
    if (!parseValue(value_atr, value)) {
        std::cout << RED << "Error: bad input => " << line << RESET << std::endl;
        return false;
    }
    if (value < 0) {
        std::cout << RED << "Error: not a positive number." << RESET << std::endl;
        return false;
    }
    if (value > 1000) {
        std::cout << RED << "Error: too large a number." << RESET << std::endl;
        return false;
    }

    double rate = findRate(date);

    if (rate < 0) {
        std::cout << RED << "Error: bad input => " << date << RESET << std::endl;
        return false;
    }

    std::cout << date << " => " << value
              << " = " << (value * rate) << std::endl;

    return true;
}

void BitcoinExchange::ProcessFile(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cout << RED << "Error: could not open file." << RESET << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		line = trim(line);
		if (line.empty())
			continue;
		if (!processLine(line))
			continue;
	}

}
