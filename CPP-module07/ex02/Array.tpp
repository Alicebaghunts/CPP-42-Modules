#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

#include <algorithm>

template <typename T>
Array<T>::Array() : data_(NULL), size_(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : data_(NULL), size_(n)
{
    allocate(size_);
}

template <typename T>
Array<T>::Array(const Array<T> &other) : data_(NULL), size_(other.size_)
{
    allocate(size_);
    for (std::size_t i = 0; i < size_; ++i)
        data_[i] = other.data_[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
    if (this != &other)
    {
        T *newData = NULL;
        if (other.size_ > 0)
        {
            newData = new T[other.size_];
            for (std::size_t i = 0; i < other.size_; ++i)
                newData[i] = other.data_[i];
        }
        delete [] data_;
        data_ = newData;
        size_ = other.size_;
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete [] data_;
}

template <typename T>
void Array<T>::allocate(std::size_t n)
{
    if (n == 0)
    {
        data_ = NULL;
        return;
    }
    data_ = new T[n];
}

template <typename T>
T &Array<T>::operator[](std::size_t index)
{
    if (index >= size_)
        throw std::out_of_range("Array index out of bounds");
    return data_[index];
}

template <typename T>
const T &Array<T>::operator[](std::size_t index) const
{
    if (index >= size_)
        throw std::out_of_range("Array index out of bounds");
    return data_[index];
}

template <typename T>
std::size_t Array<T>::size() const
{
    return size_;
}

#endif
