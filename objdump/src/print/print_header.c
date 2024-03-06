/*
** EPITECH PROJECT, 2024
** B-PSU-400-REN-4-1-nmobjdump-hugues.lejeune [WSL: Ubuntu]
** File description:
** print_header
*/

#include "objdump.h"

static void print_file_format(file_t *file, const char *path)
{
    unsigned char class = file->ehdr->e_ident[EI_CLASS];
    char *format;

    if (class == ELFCLASS32) {
        format = FORMAT_32B;
    } else {
        format = FORMAT_64B;
    }
    printf("\n%s:     file format %s\n", path, format);
}

static void print_architecture(file_t *file)
{
    (void) file;
}

void print_header(file_t *file, const char *path)
{
    print_file_format(file, path);
    print_architecture(file);
}
