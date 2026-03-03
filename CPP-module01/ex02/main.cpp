#include <iostream>
#include <string>

int main(void)
{
    std::string message = "HI THIS IS BRAIN";

    std::string* ptr = &message;
    std::string& ref = message;

    std::cout << "\033[0;36mMemory address of message :\033[0m    " << &message << std::endl;
    std::cout << "\033[0;36mMemory address held by ptr :\033[0m   " << ptr << std::endl;
    std::cout << "\033[0;36mMemory address held by ref :\033[0m   " << &ref << std::endl;

    std::cout << std::endl;

    std::cout << "\033[0;36mValue of message :\033[0m             " << message << std::endl;
    std::cout << "\033[0;36mValue pointed to by ptr :\033[0m      " << *ptr << std::endl;
    std::cout << "\033[0;36mValue referred to by ref :\033[0m     " << ref << std::endl;

    return 0;
}

