/*
** EPITECH PROJECT, 2024
** B-PSU-400-REN-4-1-nmobjdump-hugues.lejeune [WSL: Ubuntu]
** File description:
** open_file
*/

#include "nm.h"

bool open_file(file_t *file, const char *path)
{
    struct stat file_stat;
    int stat_err;

    file->fd = open(path, O_RDONLY);
    if (file->fd == -1) {
        print_error(NO_FILE, path);
        return false;
    }
    stat_err = fstat(file->fd, &file_stat);
    if (stat_err == -1) {
        perror("fstat");
        return false;
    }
    if ((file_stat.st_mode&S_IFMT) == S_IFDIR) {
        print_error(IS_DIR, path);
        return false;
    }
    file->size = file_stat.st_size;
    return true;
}
