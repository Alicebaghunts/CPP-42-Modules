#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    std::cout << PURPLE;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "        CPP06 EX00 - ScalarConverter        " << std::endl;
    std::cout << "---------------------------------------" << RESET << std::endl;

    if (argc != 2)
    {
        std::cout << PURPLE
                  << "Usage: ./convert <literal>\n"
                  << RESET;
        return 1;
    }

    ScalarConverter::convert(argv[1]);
    return 0;
}
