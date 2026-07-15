#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>
#include <cstddef>

# define RESET       "\033[0m"
# define PURPLE      "\033[38;2;150;120;170m"

template <typename T, typename F>
void iter(T *array, const std::size_t length, F func)
{
    for (std::size_t i = 0; i < length; ++i)
    {
        func(array[i]);
    }
}

#endif
