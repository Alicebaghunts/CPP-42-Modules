#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);
    numbers.push_back(50);

    try {
        std::vector<int>::const_iterator it = easyfind(numbers, 30);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        std::vector<int>::const_iterator it = easyfind(numbers, 100);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::list<int> values;

    values.push_back(5);
    values.push_back(15);
    values.push_back(25);

    try {
        std::list<int>::const_iterator it = easyfind(values, 15);
        std::cout << "Found in list: " << *it << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}