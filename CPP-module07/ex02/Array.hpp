#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>

template <typename T>
class Array
{
public:
    Array();
    Array(unsigned int n);
    Array(const Array &other);
    Array &operator=(const Array &other);
    ~Array();

    T &operator[](std::size_t index);
    const T &operator[](std::size_t index) const;

    std::size_t size() const;

private:
    T *data_;
    std::size_t size_;

    void allocate(std::size_t n);
};

#include "Array.tpp"

#endif
