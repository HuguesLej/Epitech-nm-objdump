/*
** EPITECH PROJECT, 2024
** B-PSU-400-REN-4-1-nmobjdump-hugues.lejeune [WSL: Ubuntu]
** File description:
** print_header
*/

#include "objdump.h"
#include "flags.h"

void print_header(file_t *file, const char *path)
{
    unsigned char class = file->ehdr->e_ident[EI_CLASS];
    size_t print_count = 0;

    printf("\n%s:     file format %s\n",
        path, (class == ELFCLASS32 ? FORMAT_32 : FORMAT_64));
    printf("architecture: %s, flags 0x%08x:\n",
        (file->ehdr->e_machine == EM_386 ? ARCHI_32 : ARCHI_64), file->flags);
    for (size_t i = 0; i < (sizeof(BFD_FLAGS) / sizeof(flags_t)); i++) {
        if ((file->flags & BFD_FLAGS[i].flag) != 0) {
            printf("%s%s", (print_count == 0 ? "" : ", "), BFD_FLAGS[i].name);
            print_count++;
        }
    }
    printf("\n");
    printf("start address 0x%016lx\n\n", file->ehdr->e_entry);
}
