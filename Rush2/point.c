/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#define _GNU_SOURCE
#include <stdio.h>
#include "point.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    if (this == NULL)
        raise("Class is not allocated");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
    (void)(this);
}

static char *to_string(PointClass *this)
{
    char *str;

    asprintf(&str, "<%s (%d, %d)>",
             this->base.__name__, this->x, this->y);
    return (str);
}

// Create additional functions here
static Object *add(const Object *this, const Object *other)
{
    PointClass *result = new(Point);
    PointClass *this_bis = (PointClass*) this;
    PointClass *other_bis = (PointClass*) other;

    result->x = this_bis->x + other_bis->x;
    result->y = this_bis->y + other_bis->y;
    return (result);
}

static Object *sub(const Object *this, const Object *other)
{
    PointClass *result = new(Point);
    PointClass *this_bis = (PointClass*) this;
    PointClass *other_bis = (PointClass*) other;

    result->x = this_bis->x - other_bis->x;
    result->y = this_bis->y - other_bis->y;
    return (result);
}

static Object *mul(const Object *this, const Object *other)
{
    PointClass *result = new(Point);
    PointClass *this_bis = (PointClass*) this;
    PointClass *other_bis = (PointClass*) other;

    result->x = this_bis->x * other_bis->x;
    result->y = this_bis->y * other_bis->y;
    return (result);
}

// static Object *divi(const Object *this, const Object *other)
// {
//     PointClass *result = new(Point);
//     PointClass *this_bis = (PointClass*) this;
//     PointClass *other_bis = (PointClass*) other;

//     if (other_bis->x == 0 || other_bis->y == 0)
//         raise("Error: divise by 0 is impossible");
//     else {
//         result->x = this_bis->x / other_bis->x;
//         result->y = this_bis->y / other_bis->y;
//         return (result);
//     }
// }

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ =  (to_string_t)&to_string,
        .__add__ = (binary_operator_t)&add,
        .__sub__ = (binary_operator_t)&sub,
        .__mul__ = (binary_operator_t)&mul,
        .__div__ = NULL,//(binary_operator_t)&divi,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;
