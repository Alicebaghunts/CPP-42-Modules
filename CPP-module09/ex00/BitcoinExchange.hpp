#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>

class BitcoinExchange
{
private:
    std::map<std::string, double> _database;

public:
    BitcoinExchange();
    ~BitcoinExchange();

    void loadData(const std::string& filename);
    void processInput(const std::string& filename);

};


#endif