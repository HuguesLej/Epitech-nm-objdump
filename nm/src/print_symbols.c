/*
** EPITECH PROJECT, 2024
** B-PSU-400-REN-4-1-nmobjdump-hugues.lejeune [WSL: Ubuntu]
** File description:
** print_symbols
*/

#include "nm.h"

void choose_print(symbols_t *symbol)
{
    if (symbol->addr == 0) {
        printf("%16s %c %s\n", "", symbol->type, symbol->name);
    } else {
        printf("%016lx %c %s\n", symbol->addr, symbol->type, symbol->name);
    }
}

void print_symbols(symbols_t **symbols, const char *path, bool are_mult_files)
{
    symbols_t *tmp = *symbols;
    int cmp;
    size_t print_count = 0;

    if (are_mult_files)
        printf("\n%s:\n", path);
    while (tmp != NULL) {
        cmp = strcmp(tmp->name, "");
        if (cmp == 0) {
            tmp = tmp->next;
            continue;
        }
        print_count++;
        choose_print(tmp);
        tmp = tmp->next;
    }
    if (print_count == 0)
        print_error(NO_SYM, path);
}
