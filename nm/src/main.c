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
    bool are_mult_files = false;
    int exit_code = 0;

    if (ac > 2)
        are_mult_files = true;
    if (ac == 1) {
        success = process_file(&file, "a.out", are_mult_files);
        if (!success)
            return 84;
    }
    for (int i = 1; i < ac; i++) {
        success = process_file(&file, av[i], are_mult_files);
        if (!success)
            exit_code = 84;
    }
    return exit_code;
}
