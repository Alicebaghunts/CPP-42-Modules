#include "iter.hpp"

template <typename T>
void printElement(const T &value)
{
    std::cout << value << std::endl;
}

template <typename T>
void increment(T &value)
{
    value += 1;
}

int main()
{
    int numbers[] = {1, 2, 3, 4, 5};
    std::cout << PURPLE << "Original numbers:" << RESET << std::endl;
    iter(numbers, 5, printElement<int>);

    iter(numbers, 5, increment<int>);
    std::cout << PURPLE << "Incremented numbers:" << RESET << std::endl;
    iter(numbers, 5, printElement<int>);

    const std::string words[] = {"hello", "world", "iter"};
    std::cout << PURPLE << "Const string array:" << RESET << std::endl;
    iter(words, 3, printElement<std::string>);

    char letters[] = {'a', 'b', 'c', 'd'};
    std::cout << PURPLE << "Original letters:" << RESET << std::endl;
    iter(letters, 4, printElement<char>);

    iter(letters, 4, increment<char>);
    std::cout << PURPLE << "Incremented letters:" << RESET << std::endl;
    iter(letters, 4, printElement<char>);

    return 0;
}
