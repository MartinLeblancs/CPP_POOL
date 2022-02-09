/*
** EPITECH PROJECT, 2022
** day4PM
** File description:
** print
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include "print.h"

void print_normal(const char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        write(1, &str[i], 1);
        i++;
    }
    write(1, "\n", 1);
    return;
}

void print_reverse(const char *str)
{
   char *result;
   int i = 0;
   result = malloc(sizeof(char) * strlen(str));
   strcpy(result, str);
   for (i; result[i] != '\0'; i++);

   for (i; i != -1; i--)
        write(1, &result[i], 1);
    write(1, "\n", 1);
    free(result);
    return;
}

void print_upper (const char *str) 
{
    char *result;
    result = malloc(sizeof(char) * strlen(str));
    strcpy(result, str);
    for (int i = 0; result[i] != '\0'; i++) {
        if (result[i] > 97 && result[i] < 122)
            result[i] -= 32;
    }
    print_normal(result);
    free(result);
    return;
}

void print_42 (const char *str)
{
    print_normal("42");
}

void do_action(action_t action, const char *str)
{
    void (*ptr_function[])(const char *) = {
    print_normal, print_reverse, print_upper, print_42 };

    (*ptr_function[action])(str);
}