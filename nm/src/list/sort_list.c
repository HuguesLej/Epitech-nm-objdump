/*
** EPITECH PROJECT, 2024
** B-PSU-400-REN-4-1-nmobjdump-hugues.lejeune [WSL: Ubuntu]
** File description:
** sort_list
*/

#include "nm.h"

static void perform_sort(symbols_t **symbols)
{
    symbols_t *prev = NULL;
    symbols_t *curr = *symbols;
    symbols_t *next = NULL;
    int cmp;

    while (curr->next != NULL) {
        next = curr->next;
        cmp = strcmp(curr->name, next->name);
        if (cmp > 0 && prev != NULL)
            prev->next = next;
        if (cmp > 0) {
            curr->next = next->next;
            next->next = curr;
        }
        prev = curr;
        curr = next;
    }
}

static bool is_sort(symbols_t **symbols)
{
    symbols_t *curr = *symbols;
    int cmp;

    while (curr->next != NULL) {
        cmp = strcmp(curr->name, curr->next->name);
        if (cmp > 0)
            return false;
        curr = curr->next;
    }
    return true;
}

void sort_list(symbols_t **symbols)
{
    bool sorted;

    if (*symbols == NULL)
        return;
    sorted = is_sort(symbols);
    while (!sorted) {
        perform_sort(&*symbols);
        sorted = is_sort(symbols);
    }
}
