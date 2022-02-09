/*
** EPITECH PROJECT, 2022
** Rush2
** File description:
** vertex
*/

#define _GNU_SOURCE
#include <stdio.h>
#include "vertex.h"
#include "new.h"

typedef struct
{
    Class base;
    int x;
    int y;
    int z;
} VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    if (!this)
        raise("Arguments must be initialized.");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
    (void) this;
}

static char *to_string(VertexClass *this)
{
    char *str;

    asprintf(&str, "<%s (%d, %d, %d)>",
             this->base.__name__, this->x, this->y, this->z);
    return (str);
}

static Object *add(const Object *this, const Object *other)
{
    VertexClass *result = new(Vertex);
    VertexClass *this_bis = (VertexClass*) this;
    VertexClass *other_bis = (VertexClass*) other;

    result->x = this_bis->x + other_bis->x;
    result->y = this_bis->y + other_bis->y;
    result->z = this_bis->z + other_bis->z;
    return (result);
}

static Object *sub(const Object *this, const Object *other)
{
    VertexClass *result = new(Vertex);
    VertexClass *this_bis = (VertexClass*) this;
    VertexClass *other_bis = (VertexClass*) other;

    result->x = this_bis->x - other_bis->x;
    result->y = this_bis->y - other_bis->y;
    result->z = this_bis->z - other_bis->z;
    return (result);
}

static Object *mul(const Object *this, const Object *other)
{
    VertexClass *result = new(Vertex);
    VertexClass *this_bis = (VertexClass*) this;
    VertexClass *other_bis = (VertexClass*) other;

    result->x = this_bis->x * other_bis->x;
    result->y = this_bis->y * other_bis->y;
    result->z = this_bis->z * other_bis->z;
    return (result);
}

// static Object *divi(const Object *this, const Object *other)
// {
//     VertexClass *result = new(Vertex);
//     VertexClass *this_bis = (VertexClass*) this;
//     VertexClass *other_bis = (VertexClass*) other;

//     if (other_bis->x == 0 || other_bis->y == 0|| other_bis->z == 0)
//         raise("Error: divise by 0 is impossible");
//     else {
//         result->x = this_bis->x / other_bis->x;
//         result->y = this_bis->y / other_bis->y;
//         result->z = this_bis->z / other_bis->z;
//         return (result);
//     }
// }

static const VertexClass _description = {
    {
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&to_string,
        .__add__ = (binary_operator_t)&add,
        .__sub__ = (binary_operator_t)&sub,
        .__mul__ = (binary_operator_t)&mul,
        .__div__ = NULL,//(binary_operator_t)&divi,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class *Vertex = (const Class *)&_description;