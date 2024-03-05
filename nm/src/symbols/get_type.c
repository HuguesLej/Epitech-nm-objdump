/*
** EPITECH PROJECT, 2024
** B-PSU-400-REN-4-1-nmobjdump-hugues.lejeune [WSL: Ubuntu]
** File description:
** get_type
*/

#include "nm.h"

static char find_type(char c, unsigned short st_shndx, unsigned sh_type,
    unsigned long sh_flags)
{
    if (sh_type == STT_NOTYPE)
        return 'U';
    if (st_shndx == SHN_ABS)
        return 'a';
    if (st_shndx == SHN_COMMON)
        return 'c';
    if (sh_type == SHT_NOBITS && sh_flags == (SHF_ALLOC | SHF_WRITE))
        return 'b';
    if ((sh_type == SHT_PROGBITS || sh_type == SHT_FINI_ARRAY
        || sh_type == SHT_DYNAMIC || sh_type == SHT_INIT_ARRAY)
        && sh_flags == (SHF_ALLOC | SHF_WRITE))
            return 'd';
    if ((sh_type == SHT_PROGBITS || sh_type == SHT_NOTE)
        && sh_flags == SHF_ALLOC)
            return 'r';
    if (sh_type == SHT_PROGBITS && sh_flags == (SHF_ALLOC | SHF_EXECINSTR))
        return 't';
    return c;
}

char get_type(Elf64_Sym *sym, unsigned sh_type, unsigned long sh_flags)
{
    char c = '?';
    unsigned char st_type = ELF64_ST_TYPE(sym->st_info);
    unsigned char st_bind = ELF64_ST_BIND(sym->st_info);
    bool is_up;

    if (st_type == STB_GNU_UNIQUE)
        c = 'u';
    if (st_bind == STB_WEAK && st_type == STT_OBJECT)
        c = 'v';
    if (st_bind == STB_WEAK)
        c = 'w';
    if (c == '?')
        c = find_type(c, sym->st_shndx, sh_type, sh_flags);
    if ((c == 'w' || c == 'v') && sym->st_shndx != SHN_UNDEF)
        c = char_to_uppercase(c);
    is_up = is_char_uppercase(c);
    if (st_bind == STB_GLOBAL && !is_up && c != '?')
        c = char_to_uppercase(c);
    return c;
}
