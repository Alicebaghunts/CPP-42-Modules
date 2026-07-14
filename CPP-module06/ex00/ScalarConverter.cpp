#include "ScalarConverter.hpp"

bool ScalarConverter::isSpecialLiteral(const std::string &literal) {
    return literal == "nan" || literal == "+inf" || literal == "-inf" ||
           literal == "nanf" || literal == "+inff" || literal == "-inff";
}

bool ScalarConverter::isPrintableChar(char c) {
    return c >= 32 && c <= 126;
}

bool ScalarConverter::isSignSymbol(char c) {
    return c == '+' || c == '-';
}

bool ScalarConverter::isCharacterLiteral(const std::string &literal) {
    return literal.size() == 3 && literal.front() == '\'' && literal.back() == '\'';
}

bool ScalarConverter::isIntegerLiteral(const std::string &literal) {
    if (literal.empty())
        return false;
    size_t idx = 0;
    if (isSignSymbol(literal[0]))
        idx = 1;
    if (idx == literal.size())
        return false;
    for (; idx < literal.size(); ++idx) {
        if (!std::isdigit(literal[idx]))
            return false;
    }
    return true;
}

bool ScalarConverter::hasNumericFormat(const std::string &literal) {
    size_t i = 0;
    if (isSignSymbol(literal[0]))
        i = 1;

    bool hasPoint = false;
    bool hasDigits = false;

    for (; i < literal.size(); ++i)
{
        char c = literal[i];
        if (std::isdigit(c))
        {
            hasDigits = true;
            continue;
        }
        if (c == '.')
        {
            if (hasPoint)
                return false;
            hasPoint = true;
            continue;
        }
        return false;
    }
    return hasDigits;
}

bool ScalarConverter::isFloatValue(const std::string &literal) {
    if (literal.size() < 2 || literal.back() != 'f')
        return false;

    std::string body = literal.substr(0, literal.size() - 1);
    return hasNumericFormat(body);
}

bool ScalarConverter::isDoubleValue(const std::string &literal) {
    return hasNumericFormat(literal);
}

void ScalarConverter::outputChar(double value) {
    if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
    {
        std::cout << SAGE_GREEN << "char: " << ERROR_RED << " impossible" << RESET << std::endl;
        return;
    }

    char c = static_cast<char>(value);
    if (!isPrintableChar(c))
    {
        std::cout << SAGE_GREEN << "char: " << ERROR_RED << "Non displayable" << RESET << std::endl;
        return;
    }

    std::cout << SAGE_GREEN << "char: '" << c << "'" << RESET << std::endl;
}

void ScalarConverter::outputInt(double value) {
    if (std::isnan(value) || std::isinf(value) ||
        value < static_cast<double>(std::numeric_limits<int>::min()) ||
        value > static_cast<double>(std::numeric_limits<int>::max()))
    {
        std::cout << SAGE_GREEN << "int: " << ERROR_RED << " impossible" << RESET << std::endl;
        return;
    }

    int result = static_cast<int>(value);
    std::cout << SAGE_GREEN << "int: " << result << RESET << std::endl;
}

void ScalarConverter::outputFloat(double value, const std::string &) {
    std::cout << SAGE_GREEN << "float: ";
    if (std::isnan(value))
    {
        std::cout << "nanf" << RESET << std::endl;
        return;
    }
    if (std::isinf(value))
    {
        std::cout << (value < 0 ? "-inff" : "+inff") << RESET << std::endl;
        return;
    }

    float result = static_cast<float>(value);
    std::cout << std::fixed << std::setprecision(1) << result << "f" << RESET << std::endl;
}

void ScalarConverter::outputDouble(double value, const std::string &) {
    std::cout << SAGE_GREEN << "double: ";
    if (std::isnan(value))
    {
        std::cout << "nan" << RESET << std::endl;
        return;
    }
    if (std::isinf(value))
    {
        std::cout << (value < 0 ? "-inf" : "+inf") << RESET << std::endl;
        return;
    }
    std::cout << std::fixed << std::setprecision(1) << value << RESET << std::endl;
}

void ScalarConverter::convert(const std::string &literal) {
    double value = 0.0;
    bool valid = true;

    if (isSpecialLiteral(literal)) {
        if (literal == "nan" || literal == "nanf")
            value = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "+inf" || literal == "+inff")
            value = std::numeric_limits<double>::infinity();
        else if (literal == "-inf" || literal == "-inff")
            value = -std::numeric_limits<double>::infinity();
    }
    else if (isCharacterLiteral(literal))
        value = static_cast<double>(literal[1]);
    else if (isIntegerLiteral(literal)) {
        std::istringstream iss(literal);
        int tmp;
        iss >> tmp;
        value = static_cast<double>(tmp);
    }
    else if (isFloatValue(literal)) {
        std::istringstream iss(literal.substr(0, literal.size() - 1));
        float tmp;
        iss >> tmp;
        value = static_cast<double>(tmp);
    }
    else if (isDoubleValue(literal)) {
        std::istringstream iss(literal);
        iss >> value;
    }
    else
        valid = false;

    if (!valid) {
        std::cout << SAGE_GREEN << "char:" << RESET << ERROR_RED << " impossible" << RESET << std::endl;
        std::cout << SAGE_GREEN << "int:" << RESET << ERROR_RED << " impossible" << RESET << std::endl;
        std::cout << SAGE_GREEN << "float:" << RESET << ERROR_RED << " impossible" << RESET << std::endl;
        std::cout << SAGE_GREEN << "double:" << RESET << ERROR_RED << " impossible" << RESET << std::endl;
        return;
    }

    outputChar(value);
    outputInt(value);
    outputFloat(value, literal);
    outputDouble(value, literal);
}
