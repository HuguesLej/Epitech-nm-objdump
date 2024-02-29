/*
** EPITECH PROJECT, 2024
** B-PSU-400-REN-4-1-nmobjdump-hugues.lejeune
** File description:
** main
*/

#include "nm.h"

int main(int ac, char **av)
{
    file_t file;
    bool success;
    int exit_code = 0;

    if (ac == 1) {
        success = process_file(&file, "a.out");
        if (!success)
            return 84;
    }
    for (int i = 1; i < ac; i++) {
        success = process_file(&file, av[i]);
        if (!success)
            exit_code = 84;
    }
    return exit_code;
}
