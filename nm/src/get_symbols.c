/*
** EPITECH PROJECT, 2024
** B-PSU-400-REN-4-1-nmobjdump-hugues.lejeune [WSL: Ubuntu]
** File description:
** get_symbols
*/

#include "nm.h"

static void fill_symbols(file_t *file, symbols_t *symbols, s_bounds_t *bounds,
    Elf64_Sym *sym, char *sym_tab)
{
    if (sym->st_info == STT_FILE)
        return;
    // printf("%016lx %c %s\n",
    //     sym[j].st_value,
    //     choose_char(&sym[j], shdr[sym[j].st_shndx].sh_type, shdr[sym[j].st_shndx].sh_flags),
    //     tab + sym[j].st_name
    // );
}

void get_symbols(file_t *file, symbols_t *symbols, s_bounds_t *bounds)
{
    Elf64_Sym *sym;
    char *sym_tab;
    unsigned idx;
    unsigned long max;

    for (unsigned short i = 0; i < file->ehdr->e_shnum; i++) {
        if (file->shdr[i].sh_type != SHT_SYMTAB)
            continue;
        sym = (Elf64_Sym *) (file->buf + file->shdr[i].sh_offset);
        idx = file->shdr[i].sh_link;
        sym_tab = (char *) (file->buf + file->shdr[idx].sh_offset);
        max = file->shdr[i].sh_size / sizeof(Elf64_Sym);
        for (unsigned long j = 0; j < max; j++) {
            fill_symbols(file, symbols, bounds, &sym[j], sym_tab);
        }
    }
}
