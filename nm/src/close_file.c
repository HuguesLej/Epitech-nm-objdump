/*
** EPITECH PROJECT, 2024
** B-PSU-400-REN-4-1-nmobjdump-hugues.lejeune [WSL: Ubuntu]
** File description:
** close_file
*/

#include "nm.h"

bool close_file(int fd)
{
    int close_err;

    close_err = close(fd);
    if (close_err == -1) {
        perror("close");
        return false;
    }
    return true;
}
