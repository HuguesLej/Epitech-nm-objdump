/*
** EPITECH PROJECT, 2024
** B-PSU-400-REN-4-1-nmobjdump-hugues.lejeune [WSL: Ubuntu]
** File description:
** process_file
*/

#include "objdump.h"

static bool end_process(file_t *file)
{
    bool success;

    success = close_file(file->fd);
    return success;
}

bool process_file(const char *bin, const char *path)
{
    file_t file;
    bool success;

    success = open_file(&file, bin, path);
    if (!success)
        return false;
    success = get_file_content(&file, bin, path);
    if (!success)
        return false;
    get_symbols(&file, &symbols);
    sort_list(&symbols);
    print_symbols(&symbols, bin, path, are_mult_files);
    success = end_process(&file, &symbols);
    if (!success)
        return false;
    return true;
}
