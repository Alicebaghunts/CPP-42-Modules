#include <iostream>
#include <string>

int main(void)
{
    std::string message = "HI THIS IS BRAIN";

    std::string* stringPTR = &message;
    std::string& stringREF = message;

    std::cout << "Memory address of the string variable:    " << &message << std::endl;
    std::cout << "Memory address held by stringPTR:         " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF:         " << &stringREF << std::endl;

    std::cout << std::endl;

    std::cout << "Value of the string variable:             " << message << std::endl;
    std::cout << "Value pointed to by stringPTR:             " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF:             " << stringREF << std::endl;

    return 0;
}

