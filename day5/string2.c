/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD05-martin.leblancs
** File description:
** The second string
*/

#include "string.h"

void append_s(struct string_t *this, const string_t *ap)
{
    if (this->str == NULL || ap->str == NULL)
        return;
    this->str = realloc(this->str, strlen(this->str) + strlen(ap->str) + 1);
    strcat(this->str, ap->str);
}

void append_c (string_t *this, const char *ap)
{
    if (this->str == NULL || ap == NULL)
        return;
    this->str = realloc(this->str, strlen(this->str) + strlen(ap) + 1);
    strcat(this->str, ap);
}

char at(const string_t *this, size_t pos)
{
    if (pos < 0 || pos > strlen(this->str))
        return (-1);
    if (this && this->str && this->str[pos] != '\0')
        return (this->str[pos]);
    else
        return (-1);
}

void clear (string_t *this)
{
    if(this)
        memset(this, 0, sizeof(this));
}

int length (const string_t *this)
{
    if (this->str == NULL)
        return (-1);
    else
        return (strlen(this->str));
}