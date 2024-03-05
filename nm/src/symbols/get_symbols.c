/*
** EPITECH PROJECT, 2024
** B-PSU-400-REN-4-1-nmobjdump-hugues.lejeune [WSL: Ubuntu]
** File description:
** get_symbols
*/

#include "nm.h"

static void fill_symbols(file_t *file, symbols_t **symbols, Elf64_Sym *sym,
    char *sym_tab)
{
    symbols_t *new;
    unsigned short idx;
    unsigned sh_type;
    unsigned long sh_flags;

    if (sym->st_info == STT_FILE)
        return;
    idx = sym->st_shndx;
    sh_type = file->shdr[idx].sh_type;
    sh_flags = file->shdr[idx].sh_flags;
    new = add_element(symbols);
    new->addr = sym->st_value;
    new->name = sym_tab + sym->st_name;
    new->type = get_type(sym, sh_type, sh_flags);
}

void get_symbols(file_t *file, symbols_t **symbols)
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
            fill_symbols(file, symbols, &sym[j], sym_tab);
        }
    }
}
