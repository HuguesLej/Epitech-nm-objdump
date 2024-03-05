/*
** EPITECH PROJECT, 2024
** B-PSU-400-REN-4-1-nmobjdump-hugues.lejeune [WSL: Ubuntu]
** File description:
** free_list
*/

#include "nm.h"

void free_list(symbols_t **symbols)
{
    symbols_t *tmp = *symbols;
    symbols_t *next = NULL;

    while (tmp != NULL) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    *symbols = NULL;
}
