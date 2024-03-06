/*
** EPITECH PROJECT, 2024
** B-PSU-400-REN-4-1-nmobjdump-hugues.lejeune
** File description:
** main
*/

#include "objdump.h"

int main(int ac, char **av)
{
    bool success;
    int exit_code = 0;

    if (ac == 1) {
        success = process_file(av[0], "a.out");
        if (!success)
            return 84;
    }
    for (int i = 1; i < ac; i++) {
        success = process_file(av[0], av[i]);
        if (!success)
            exit_code = 84;
    }
    return exit_code;
}
