/*
** EPITECH PROJECT, 2024
** B-PSU-400-REN-4-1-nmobjdump-hugues.lejeune [WSL: Ubuntu]
** File description:
** get_file_content
*/

#include "commons.h"

bool get_file_content(file_t *file, const char *bin, const char *path)
{
    file->buf = mmap(NULL, file->size, PROT_READ, MAP_PRIVATE, file->fd, 0);
    if (file->buf == MAP_FAILED) {
        perror("mmap");
        return false;
    }
    file->ehdr = (Elf64_Ehdr *) file->buf;
    if (file->ehdr->e_type != ET_REL && file->ehdr->e_type != ET_EXEC
        && file->ehdr->e_type != ET_DYN) {
            print_error(WG_FILE, bin, path);
            return false;
    }
    if (file->ehdr->e_type == ET_REL)
        file->flags = REL_FLAGS;
    if (file->ehdr->e_type == ET_EXEC)
        file->flags = EXEC_FLAGS;
    if (file->ehdr->e_type == ET_DYN)
        file->flags = DYN_FLAGS;
    file->shdr = (Elf64_Shdr *) (file->buf + file->ehdr->e_shoff);
    return true;
}
