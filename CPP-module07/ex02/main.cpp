#include "Array.hpp"
#include <iostream>
#include <string>

int main()
{
    std::cout << "Empty array test" << std::endl;
    Array<int> empty;
    std::cout << "size = " << empty.size() << std::endl;

    Array<int> numbers(5);
    for (std::size_t i = 0; i < numbers.size(); ++i)
        numbers[i] = static_cast<int>(i) * 2;

    std::cout << "Numbers:" << std::endl;
    for (std::size_t i = 0; i < numbers.size(); ++i)
        std::cout << numbers[i] << std::endl;

    std::cout << "Copy test" << std::endl;
    Array<int> copy(numbers);
    copy[0] = 42;
    std::cout << "original[0] = " << numbers[0] << std::endl;
    std::cout << "copy[0] = " << copy[0] << std::endl;

    std::cout << "Assignment test" << std::endl;
    Array<int> assigned;
    assigned = numbers;
    assigned[1] = 99;
    std::cout << "original[1] = " << numbers[1] << std::endl;
    std::cout << "assigned[1] = " << assigned[1] << std::endl;

    std::cout << "String array test" << std::endl;
    Array<std::string> words(2);
    words[0] = "hello";
    words[1] = "world";
    std::cout << words[0] << " " << words[1] << std::endl;

    try
    {
        std::cout << "Out of bounds access: " << std::endl;
        std::cout << numbers[10] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
