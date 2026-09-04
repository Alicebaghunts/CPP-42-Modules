#include "MutantStack.hpp"
#include <iostream>
#include <string>

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Elements:" << std::endl;

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "Reverse:" << std::endl;

    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();

    while (rit != rite) {
        std::cout << *rit << std::endl;
        ++rit;
    }

    MutantStack<int> copy(mstack);

    std::cout << "Copied stack:" << std::endl;

    for (MutantStack<int>::iterator i = copy.begin(); i != copy.end(); ++i)
    {
        std::cout << *i << std::endl;
    }

    return 0;
}