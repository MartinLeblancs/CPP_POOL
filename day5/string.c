/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD05-martin.leblancs
** File description:
** string
*/

#include "string.h"

void string_init(string_t *this, const char *s)
{
    if (s)
        this->str = strdup(s);
    else
    this->str = NULL;
    this->assign_s = assign_s;
    this->assign_c = assign_c;
    this->append_s = append_s;
    this->append_c = append_c;
    this->compare_s = compare_s;
    this->compare_c = compare_c;
    this->length = length;
    this->clear = clear;
    this->at = at;
    this->copy = copy;
    this->c_str = c_str;
    this->empty = empty;
}

void string_destroy(string_t *this)
{
    if (this->str)
        free(this->str);
    memset(this, 0, sizeof(string_t));
}

void assign_s(string_t *this, const string_t *str)
{
    if (str) {
        free(this->str);
        this->str = strdup(str->str);
    }
    else
    this->str = NULL;
}

void assign_c(string_t *this, const char *s)
{
    if (s) {
        free(this->str);
        this->str = strdup(s);
    }
    else
        this->str = NULL;
}