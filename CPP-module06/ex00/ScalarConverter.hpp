#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

#define SAGE_GREEN  "\033[38;2;163;177;138m"
#define DUSTY_BLUE  "\033[38;2;109;130;153m"
#define SOFT_PURPLE "\033[38;2;150;120;170m"
#define ERROR_RED "\033[38;2;220;40;40m"
#define RESET       "\033[0m"

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &);
    ScalarConverter &operator=(const ScalarConverter &);
    ~ScalarConverter();

    static bool isSpecialLiteral(const std::string &literal);
    static bool isPrintableChar(char c);
    static bool isIntegerLiteral(const std::string &literal);
    static bool isFloatValue(const std::string &literal);
    static bool isDoubleValue(const std::string &literal);
    static bool isCharacterLiteral(const std::string &literal);
    static bool hasNumericFormat(const std::string &literal);
    static bool isSignSymbol(char c);

    static void outputChar(double value);
    static void outputInt(double value);
    static void outputFloat(double value, const std::string &);
    static void outputDouble(double value, const std::string &);

public:
    static void convert(const std::string &literal);
};

#endif
