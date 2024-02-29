/*
** EPITECH PROJECT, 2024
** B-PSU-400-REN-4-1-nmobjdump-hugues.lejeune
** File description:
** open_file
*/

#include "nm.h"

bool is_uppercase(char c)
{
    if (c < 'A' || c > 'Z')
        return false;
    return true;
}

char char_to_uppercase(char c)
{
    char upper_c = c - 32;

    return upper_c;
}

char choose_char(Elf64_Sym *sym, unsigned sh_type, unsigned long sh_flags)
{
    char characters[] = {
        'D', 'd',
        'G', 'g',
        'i',
        'I',
        'N',
        'n',
        'p',
        'R', 'r',
        'S', 's',
        'T', 't',
        '-'
    };
    (void) characters;

    (void) sh_flags;

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
    }

    if ((c == 'w' || c == 'v') && sym->st_shndx != SHN_UNDEF) {
        c = char_to_uppercase(c);
    }

    if (st_bind == STB_GLOBAL && !is_uppercase(c) && c != '?') {
        c = char_to_uppercase(c);
    }


    return c;
}

#include <string.h>

bool open_file(const char *str)
{
    int fd;
    void *buf;
    struct stat s;
    Elf64_Ehdr *ehdr;

    fd = open(str, O_RDONLY);
    if (fd == -1)
        return false;
    fstat(fd, &s);
    buf = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (buf == MAP_FAILED) {
        perror("mmap");
        return false;
    }
    ehdr = (Elf64_Ehdr *) buf;
    if (ehdr->e_type != ET_REL && ehdr->e_type != ET_EXEC && ehdr->e_type != ET_DYN)
        return false;


    Elf64_Shdr *shdr = (Elf64_Shdr *) (buf + ehdr->e_shoff);

    for (unsigned short i = 0; i < ehdr->e_shnum; i++) {
        if (shdr[i].sh_type == SHT_SYMTAB) {
            Elf64_Sym *sym = (Elf64_Sym *) (buf + shdr[i].sh_offset);
            char *tab = (char *) (buf + shdr[shdr[i].sh_link].sh_offset);

            for (unsigned long j = 0; j < (shdr[i].sh_size / sizeof(Elf64_Sym)); j++) {
                if (sym[j].st_info != STT_FILE) {
                    printf("%016lx %c %s\n",
                        sym[j].st_value,
                        choose_char(&sym[j], shdr[sym[j].st_shndx].sh_type, shdr[sym[j].st_shndx].sh_flags),
                        tab + sym[j].st_name
                    );
                }
            }
        }
    }


    close(fd);

    return true;
}
