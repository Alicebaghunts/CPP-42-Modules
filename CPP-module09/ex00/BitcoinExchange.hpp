#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#define RED   "\033[31m"
#define RESET "\033[0m"

#include <map>
#include <string>

class BitcoinExchange
{
private:
	std::map<std::string, double> _database;

	bool isValidDate(const std::string &date) const;
	bool isLeapYear(int year) const;
	double findRate(const std::string &date) const;
	std::string trim(const std::string &str) const;
	bool parseValue(const std::string &str, double &out) const;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	void LoadDataBase(const std::string &filename);
	void ProcessFile(const std::string &filename);
	bool processLine(const std::string &line);
};

#endif
