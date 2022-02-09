/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD05-martin.leblancs
** File description:
** The third string
*/

#include "string.h"

int compare_s (const string_t *this, const string_t *str)
{
    return (strcmp(this->str, str->str));
}

int compare_c (const string_t *this, const char *str)
{
    return (strcmp(this->str, str));
}

size_t copy (const string_t *this, char *s, size_t n, size_t pos)
{
    int count_char_copy = 0;
    int the_pos = 0;
    if (strlen(this->str) < pos)
        return (0);
    the_pos = pos;
    for (int i = 0; i < n && this->str[the_pos]; i++, the_pos++) {
        s[i] = this->str[the_pos];
        count_char_copy++;
    }
    return (count_char_copy);
}

const char *c_str(const string_t *this)
{
    return (this->str);
}

int empty (const string_t *this)
{
    if (this->str == NULL)
        return (1);
    else
        return (0);
}