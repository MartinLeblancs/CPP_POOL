/*
** EPITECH PROJECT, 2022
** day4PM
** File description:
** integer_list
*/
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "int_list.h"

unsigned int int_list_get_size (int_list_t list)
{
    unsigned int count = 0;
    while (list != NULL) {
        count++;
        list = list->next;
    }
    return (count);
}

bool int_list_is_empty(int_list_t list)
{
    if (list == NULL)
        return (true);
    else 
        return (false);
}   

void int_list_dump (int_list_t list)
{   
    while (list != NULL)
    {
        printf("%d\n", list->value);
        list = list->next;
    }
}

bool int_list_add_elem_at_front(int_list_t *front_ptr, int elem)
{
    int_list_t NewElem = malloc(sizeof(int_list_t));
    NewElem->value = elem;
    NewElem->next = *front_ptr;
    if (NewElem == NULL) {
        free(NewElem);
        return (false);
    }
    *front_ptr = NewElem;
    free(NewElem);
    return (true);
}

bool int_list_add_elem_at_back(int_list_t *front_ptr, int elem)
{
    int_list_t NewElem = malloc(sizeof(int_list_t));
    NewElem->value = elem;
    NewElem->next = NULL;
    if (NewElem == NULL) {
        *front_ptr = NewElem;
        return (false);
    }
    int_list_t LastElem;
    LastElem = *front_ptr;
    while (LastElem->next != NULL)
        LastElem = LastElem->next;

    LastElem->next = NewElem;
    free(NewElem);
    return (true);
}

bool int_list_add_elem_at_position(int_list_t *front_ptr, int elem, unsigned int position) 
{
    if (position == 0)
        int_list_add_elem_at_front(front_ptr, elem);
    else {
        int_list_t NewElem = malloc(sizeof(int_list_t));
        NewElem->value = elem;
        NewElem->next = NULL;
        if (NewElem == NULL) {
            free(NewElem);
            return (false);
        }
        int_list_t LastElem = *front_ptr;
        for (unsigned int i = 0; i != position; i++) {
            if (LastElem->next == NULL)
                return (false);
            LastElem = LastElem->next;
        }
        LastElem->next = NewElem;
        free(NewElem);
        return (true);
    }
}

int int_list_get_elem_at_front(int_list_t list)
{
    if (list == NULL)
        return (0);
    else 
        return (list->value);
}

int int_list_get_elem_at_back(int_list_t list)
{
    if (list == NULL)
        return (0);
    while (list->next != NULL)
        list = list->next;

    return (list->value);
}

int int_list_get_elem_at_position(int_list_t list, unsigned int position)
{
    if (position == 0)
        int_list_get_elem_at_front(list);
    else {
        if (list == NULL)
            return (0);
        for (unsigned int i = 0; i < position; i++) {
            if (list->next == NULL)
                return (0);
            list = list->next;
        }
        return (list->value);
    }
}

bool int_list_del_elem_at_front(int_list_t *front_ptr)
{
    int_list_t del;

    if ((*front_ptr) == NULL) 
        return (false);
    del = *front_ptr;
    *front_ptr = del->next;
    free(del);
    return (true);
}

bool int_list_del_elem_at_back(int_list_t *front_ptr)
{
    int_list_t new;

    if ((*front_ptr) == NULL)
        return (false);
    new = *front_ptr;
    while (new->next != NULL)
        new = new->next;
    int_list_t LastElem = new->next;
    new->next = NULL;
    free(LastElem);
    return (true);
}

bool int_list_del_elem_at_position(int_list_t *front_ptr, unsigned int position)
{
    int_list_t new;

    if ((*front_ptr) == NULL)
        return (false);
    new = *front_ptr;
    if (position == 0)
        int_list_del_elem_at_front(front_ptr);
    
    for (unsigned int i = 0; new != NULL && i < position - 1; i++) 
        new = new->next;
    if (new == NULL || new->next == NULL)
        return (false);

    int_list_t next = new->next;
    free(new->next);
    new->next = next;
    return (true);
}

void int_list_clear (int_list_t *front_ptr)
{
    int_list_t del;

    while ((*front_ptr) != NULL) {
        del = *front_ptr;
        *front_ptr = del->next;
        free(del);
    }
}