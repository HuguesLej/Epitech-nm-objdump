/*
** EPITECH PROJECT, 2024
** B-PSU-400-REN-4-1-nmobjdump-hugues.lejeune [WSL: Ubuntu]
** File description:
** get_type
*/

#include "nm.h"

char get_type(Elf64_Sym *sym, unsigned sh_type, unsigned long sh_flags)
{
    char c = '?';
    unsigned char st_type = ELF64_ST_TYPE(sym->st_info);
    unsigned char st_bind = ELF64_ST_BIND(sym->st_info);


    if (st_type == STB_GNU_UNIQUE) {
        c = 'u';
    }

    if (st_bind == STB_WEAK && st_type == STT_OBJECT) {
        c = 'v';
    } else if (st_bind == STB_WEAK) {
        c = 'w';
    } else if (sh_type == STT_NOTYPE) {
        c = 'U';
    } else if (sym->st_shndx == SHN_ABS) {
        c = 'a';
    } else if (sym->st_shndx == SHN_COMMON) {
        c = 'c';
    } else if (sh_type == SHT_NOBITS && sh_flags == (SHF_ALLOC|SHF_WRITE)) {
        c = 'b';
    } else if ((sh_type == SHT_PROGBITS || sh_type == SHT_FINI_ARRAY || sh_type == SHT_DYNAMIC || sh_type == SHT_INIT_ARRAY) && sh_flags == (SHF_ALLOC|SHF_WRITE)) {
        c = 'd';
    } else if ((sh_type == SHT_PROGBITS || sh_type == SHT_NOTE) && sh_flags == SHF_ALLOC) {
        c = 'r';
    } else if (sh_type == SHT_PROGBITS && sh_flags == (SHF_ALLOC | SHF_EXECINSTR)) {
        c = 't';
    }

    if ((c == 'w' || c == 'v') && sym->st_shndx != SHN_UNDEF) {
        c = char_to_uppercase(c);
    }

    if (st_bind == STB_GLOBAL && !is_char_uppercase(c) && c != '?') {
        c = char_to_uppercase(c);
    }


    return c;
}
