#include <stdio.h>
#include "string.h"

int main (void)
{
    string_t s;

    string_init (&s, "Hello World");
    printf("%c", at(&s, 7));
    string_destroy(&s);
    return (0);
}