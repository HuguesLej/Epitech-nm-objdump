/*
** EPITECH PROJECT, 2024
** B-PSU-400-REN-4-1-nmobjdump-hugues.lejeune [WSL: Ubuntu]
** File description:
** print_error
*/

#include "nm.h"

void print_error(unsigned flag, const char *bin, const char *path)
{
    if (flag == NO_FILE) {
        dprintf(STDERR_FILENO, "%s: '%s': No such file\n", bin, path);
    }
    if (flag == IS_DIR) {
        dprintf(STDERR_FILENO, "%s: Warning: '%s' is a directory\n", bin, path);
    }
    if (flag == WG_FILE) {
        dprintf(STDERR_FILENO, "%s: %s: file format not recognized\n", bin, path);
    }
    if (flag == NO_SYM) {
        dprintf(STDERR_FILENO, "%s: %s: no symbols\n", bin, path);
    }
}
