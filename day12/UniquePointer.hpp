/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <iostream>

template<typename Type>
class UniquePointer
{
    public:
        UniquePointer(Type *pointer){_pointer = pointer;}
        UniquePointer(const UniquePointer<Type> &) = delete;
        ~UniquePointer(){delete(_pointer);};
        UniquePointer &operator=(const UniquePointer &) = delete;
        void operator=(Type *ptr);
        UniquePointer(){_pointer = nullptr;};
        void reset ();
        Type *get ();
        Type *operator->();
    private:
        Type *_pointer;
};

template<typename Type>
void UniquePointer<Type>::operator=(Type *ptr)
{
    delete(_pointer);
    _pointer = ptr;
}

template<typename Type>
void UniquePointer<Type>::reset()
{
    delete(_pointer);
    _pointer = nullptr;
}

template<typename Type>
Type *UniquePointer<Type>::get()
{
    return (_pointer);
}

template<typename Type>
Type *UniquePointer<Type>::operator->()
{
    return(_pointer);
}