/*
** EPITECH PROJECT, 2022
** kreog rush
** File description:
** new and delete class
*/

#include "new.h"

Object *va_new(const Class *class, va_list* ap)
{
    Object *obj = malloc(class->__size__);

    if (!obj)
        raise("Error: Out of memory while allocating memory");
    if (!memcpy(obj, class, class->__size__))
        raise("Error: No pointer return while copying memory");
    if (class->__ctor__)
        class->__ctor__(obj, ap);
    return (obj);
}

Object *new(const Class *class, ...)
{
    va_list args;
    Object *instance = NULL;

    if (!class)
        raise("Error: NULL");
    va_start(args, class);
    instance = va_new(class, &args);
    va_end(args);
    return (instance);
}

void delete(Object *ptr)
{
    Class *class = (Class *)ptr;

    if (!ptr)
        raise("Delete can't free NULL");
    if (class->__dtor__)
        class->__dtor__(ptr);
    free(ptr);
}