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
        success = open_file(&file, "a.out");
        if (!success)
            return 84;
        close_file(file.fd);
    }
    for (int i = 1; i < ac; i++) {
        success = open_file(&file, av[i]);
        if (!success) {
            exit_code = 84;
            continue;
        }
        close_file(file.fd);
    }
    return exit_code;
}
