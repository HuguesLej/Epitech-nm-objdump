/*
** EPITECH PROJECT, 2024
** B-PSU-400-REN-4-1-nmobjdump-hugues.lejeune
** File description:
** main
*/

#include "nm.h"

int main(int ac, char **av)
{
    int exit_code = 0;

    (void)exit_code;
    if (ac == 1) {
        unnamed("a.out");
    }
    for (int i = 1; i < ac; i++) {
        unnamed(av[i]);
    }
    return 0;
}
