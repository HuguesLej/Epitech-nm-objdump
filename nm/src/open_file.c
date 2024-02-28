/*
** EPITECH PROJECT, 2024
** B-PSU-400-REN-4-1-nmobjdump-hugues.lejeune
** File description:
** open_file
*/

#include "nm.h"

char choose_char(Elf64_Sym *sym, unsigned sh_type, unsigned long sh_flags)
{
    char characters[] = {
        'A',
        'B', 'b',
        'C', 'c',
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
        'U',
        'u',
        'V', 'v',
        'W', 'w',
        '-',
        '?'
    };
    (void) characters;

    (void) sh_type;
    (void) sh_flags;

    unsigned char c = '?';


    if (ELF64_ST_BIND(sym->st_info) == STB_WEAK) {
        if (sym->st_shndx == SHN_UNDEF) {
            c = 'w';
        } else {
            c = 'W';
        }
    }


    return c;
}

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
