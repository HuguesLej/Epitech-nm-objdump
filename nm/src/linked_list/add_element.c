/*
** EPITECH PROJECT, 2024
** B-PSU-400-REN-4-1-nmobjdump-hugues.lejeune [WSL: Ubuntu]
** File description:
** add_element
*/

#include "nm.h"

symbols_t *add_element(s_bounds_t *sym_bounds)
{
    symbols_t *symbol = malloc(sizeof(symbols_t));

    if (sym_bounds->start == NULL)
        sym_bounds->start = symbol;
    if (sym_bounds->end != NULL)
        sym_bounds->end->next = symbol;
    symbol->prev = sym_bounds->end;
    symbol->next = NULL;
    sym_bounds->end = symbol;
    return symbol;
}
