/*
** EPITECH PROJECT, 2022
** Array
** File description:
** Array
*/

#ifndef __ARRAY__
#define __ARRAY__

#include <iostream>
#include <stdexcept>
#include <initializer_list>
#include <functional>

template <typename Type, std::size_t Size>
class Array
{
    public:
        Array() {for (std::size_t i = 0; i < Size; i++) std::fill(_array, _array + Size, 0);};
        ~Array(){};
        Type &operator[](const std::size_t &index) const;
        Type &operator[](const std::size_t &index);
        std::size_t size() const;
        void forEach (const std::function<void(const Type &)> &task) const;
        template <typename U>
        Array<U, Size> convert(const std::function<U (const Type &)> &converter) const
        {
            Array<U, Size> obj;
            for (size_t i = 0; i < Size; i++) {
                obj[i] = converter(this->_array[i]);
            }
            return (obj);
        }

    private:
        Type _array[Size];
};

template <typename Type, std::size_t Size>
Type &Array<Type, Size>::operator[](const std::size_t &index)
{
    if (index >= Size)
        throw std::invalid_argument("Out of range");
    return (_array[index]);
}

template <typename Type, std::size_t Size>
Type &Array<Type, Size>::operator[](const std::size_t &index) const
{
    if (index >= Size)
        throw std::invalid_argument("Out of range");
    return (_array[index]);
}

template <typename Type, std::size_t Size>
std::size_t size()
{
    return (Size);
}

template <typename Type, std::size_t Size>
void Array<Type, Size>::forEach(const std::function<void(const Type &)> &task) const
{
    for (size_t i = 0; i < Size; i++)
    {
        task(_array[i]);
    }
}

template <typename Type, std::size_t Size>
std::ostream &operator<<(std::ostream &os, Array<Type, Size> &array)
{
    size_t i = 0;
    os << "[";
    for (i = 0; i < Size - 1; i++) {
        os << array[i];
        os << ", ";
    }
    os << array[i];
    os << "]";
    return(os);
}

template <typename Type, std::size_t Size>
std::ostream &operator<<(std::ostream &os, const Array<Type, Size> &array)
{
    size_t i = 0;
    os << "[";
    for (i = 0; i < Size - 1; i++) {
        os << array[i];
        os << ", ";
    }
    os << array[i];
    os << "]";
    return(os);
}

#endif