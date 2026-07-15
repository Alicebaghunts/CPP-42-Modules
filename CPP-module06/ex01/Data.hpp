#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iostream>

#define SOFT_PURPLE  "\033[38;2;150;120;170m"
#define SAGE_GREEN  "\033[38;2;163;177;138m"
#define DUSTY_BLUE  "\033[38;2;109;130;153m"
#define RESET       "\033[0m"

struct Data
{
    std::string name;
    int value;
};

#endif