/*
** EPITECH PROJECT, 2024
** B-PSU-400-REN-4-1-nmobjdump-hugues.lejeune [WSL: Ubuntu]
** File description:
** print_error
*/

#include "nm.h"

void print_error(unsigned flag, const char *str)
{
    if (flag == NO_FILE) {
        dprintf(STDERR_FILENO, "my_nm: '%s': No such file\n", str);
    }
    if (flag == IS_DIR) {
        dprintf(STDERR_FILENO, "my_nm: Warning: '%s' is a directory\n", str);
    }
    if (flag == WG_FILE) {
        dprintf(STDERR_FILENO, "my_nm: %s: file format not recognized\n", str);
    }
}
