/*
** EPITECH PROJECT, 2024
** B-PSU-400-REN-4-1-nmobjdump-hugues.lejeune [WSL: Ubuntu]
** File description:
** process_file
*/

#include "nm.h"

bool process_file(file_t *file, const char *path)
{
    bool success;

    success = open_file(file, path);
    if (!success)
        return false;
    success = get_file_content(file, path);
    if (!success)
        return false;
    success = close_file(file->fd);
    if (!success)
        return false;
    return true;
}
