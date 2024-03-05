/*
** EPITECH PROJECT, 2024
** B-PSU-400-REN-4-1-nmobjdump-hugues.lejeune [WSL: Ubuntu]
** File description:
** print_symbols
*/

#include "nm.h"

void print_symbols(symbols_t **symbols, const char *path, bool are_mult_files)
{
    symbols_t *tmp = *symbols;
    int cmp;

    if (are_mult_files)
        printf("\n%s:\n", path);
    while (tmp != NULL) {
        cmp = strcmp(tmp->name, "");
        if (cmp == 0) {
            tmp = tmp->next;
            continue;
        }
        if (tmp->addr == 0) {
            printf("%16s %c %s\n", "", tmp->type, tmp->name);
        } else {
            printf("%016lx %c %s\n", tmp->addr, tmp->type, tmp->name);
        }
        tmp = tmp->next;
    }
}
