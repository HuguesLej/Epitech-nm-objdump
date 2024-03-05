/*
** EPITECH PROJECT, 2024
** B-PSU-400-REN-4-1-nmobjdump-hugues.lejeune [WSL: Ubuntu]
** File description:
** add_element
*/

#include "nm.h"

symbols_t *add_element(symbols_t **symbols)
{
    symbols_t *node = malloc(sizeof(symbols_t));
    symbols_t *tmp = *symbols;

    node->next = NULL;
    node->name = NULL;
    node->addr = 0;
    node->type = 0;
    if (*symbols == NULL) {
        *symbols = node;
        return node;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = node;
    return node;
}
