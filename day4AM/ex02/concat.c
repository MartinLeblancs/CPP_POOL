/*
** EPITECH PROJECT, 2022
** ex02
** File description:
** concat
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "concat.h"

void concat_strings(const char *str1 ,const char *str2, char **res) 
{
    int i = 0; 
    int j = 0;
    res[0] = malloc(sizeof(char) * (strlen(str1) + strlen(str2)) + 1);
    for(i = 0; str1[i] == ' '; i++);

    for (i = 0; str1[i] != '\0'; i++, j++)
        res[0][j] = str1[i];
    for (i = 0; str2[i] != '\0'; i++, j++)
        res[0][j] = str2[i];

    res[0][j++] = '\0';
}

void concat_struct (concat_t *str) 
{
    int i = 0; 
    int j = 0;
    str->res = malloc(sizeof(char) * 
    (strlen(str->str1) + strlen(str->str2)) + 1);
    for(i = 0; str->str1[i] == ' '; i++);

    for (i = 0; str->str1[i] != '\0'; i++, j++)
        str->res[j] = str->str1[i];
    for (i = 0; str->str2[i] != '\0'; i++, j++)
        str->res[j] = str->str2[i];

    str->res[j++] = '\0';
}